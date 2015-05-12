package ru.ifmo.ctddev.filippov.crawler;

import info.kgeorgiy.java.advanced.crawler.*;

import java.io.File;
import java.io.IOException;
import java.net.MalformedURLException;
import java.util.Arrays;
import java.util.List;
import java.util.concurrent.*;
import java.util.stream.Collectors;

public class WebCrawler implements Crawler {
    private final Downloader downloader;
    private final ExecutorService downloadService, extractService;
    private final int perHost;

    public WebCrawler(Downloader downloader, int dowloaders, int extractors, int perHost) {
        this.downloader = downloader;
        this.downloadService = Executors.newFixedThreadPool(dowloaders);
        this.extractService = Executors.newFixedThreadPool(extractors);
        this.perHost = perHost;
    }

    private class Pair<K, V> {
        K first;
        V second;

        Pair(K first, V second) {
            this.first = first;
            this.second = second;
        }

        K getFirst() {
            return first;
        }

        V getSecond() {
            return second;
        }
    }

    private void processExtract(int depth,
                                Document document,
                                final ConcurrentHashMap<String, Object> result,
                                final ConcurrentHashMap<String, IOException> errors,
                                final ConcurrentHashMap<String, Object> visited,
                                final ConcurrentHashMap<String, Semaphore> semaphores,
                                final ConcurrentHashMap<String, ConcurrentLinkedDeque<Pair<String, Integer>>> downloadQueues,
                                final Semaphore clocks) {
        try {
            if (depth > 1) {
                List<String> documentLinks = document.extractLinks();
                documentLinks.stream().distinct().filter(x -> !visited.containsKey(x)).forEach(url -> {
                    try {
                        String host = URLUtils.getHost(url);
                        downloadQueues.putIfAbsent(host, new ConcurrentLinkedDeque<>());
                        downloadQueues.get(host).addLast(new Pair<>(url, depth - 1));
                        semaphores.putIfAbsent(host, new Semaphore(perHost));
                        clocks.acquire();
                        downloadService.submit(() -> processDownload(host, result, errors, visited, semaphores, downloadQueues, clocks));
                    } catch (MalformedURLException e) {
                        System.out.println(e.toString());
                    } catch (InterruptedException e) {
                        System.out.println(e.toString());
                    }
                });
            }
        } catch (IOException e) {
            System.out.println(e.toString());
        } finally {
            clocks.release();
        }
    }

    private void processDownload(String host,
                                 final ConcurrentHashMap<String, Object> result,
                                 final ConcurrentHashMap<String, IOException> errors,
                                 final ConcurrentHashMap<String, Object> visited,
                                 final ConcurrentHashMap<String, Semaphore> semaphores,
                                 final ConcurrentHashMap<String, ConcurrentLinkedDeque<Pair<String, Integer>>> dowloadQueues,
                                 final Semaphore clocks) {
        try {
            if (semaphores.get(host).tryAcquire() && !dowloadQueues.get(host).isEmpty()) {
                Pair<String, Integer> pair = dowloadQueues.get(host).poll();
                if (pair == null) {
                    return;
                }
                String url = pair.getFirst();
                int depth = pair.getSecond();
                if (visited.putIfAbsent(url, new Object()) == null) {
                    try {
                        Document document = downloader.download(url);
                        result.put(url, new Object());
                        clocks.acquire();
                        extractService.submit(() -> processExtract(depth, document, result, errors, visited, semaphores, dowloadQueues, clocks));
                    } catch (IOException e) {
                        errors.put(url, e);
                    } catch (InterruptedException e) {
                        System.out.println(e.toString());
                    } finally {
                        semaphores.get(host).release();
                        if (!dowloadQueues.get(host).isEmpty()) {
                            try {
                                clocks.acquire();
                                downloadService.submit(() -> processDownload(host, result, errors, visited, semaphores, dowloadQueues, clocks));
                            } catch (InterruptedException e) {
                                System.out.println(e.toString());
                            }
                        }
                    }
                }
            }
        } finally {
            clocks.release();
        }
    }

    @Override
    public Result download(String url, int depth) {
        final int semaphorSize = Integer.MAX_VALUE - 100;
        final Semaphore clocker = new Semaphore(semaphorSize);
        final ConcurrentHashMap<String, Object> result = new ConcurrentHashMap<>();
        final ConcurrentHashMap<String, IOException> errors = new ConcurrentHashMap<>();
        final ConcurrentHashMap<String, Object> visited = new ConcurrentHashMap<>();
        final ConcurrentHashMap<String, Semaphore> semaphores = new ConcurrentHashMap<>();
        final ConcurrentHashMap<String, ConcurrentLinkedDeque<Pair<String, Integer>>> downloadQueues = new ConcurrentHashMap<>();

        try {
            String host = URLUtils.getHost(url);
            semaphores.putIfAbsent(host, new Semaphore(perHost));
            downloadQueues.putIfAbsent(host, new ConcurrentLinkedDeque<>());
            downloadQueues.get(host).addLast(new Pair<>(url, depth));
            clocker.acquire();
            downloadService.submit(() -> processDownload(host, result, errors, visited, semaphores, downloadQueues, clocker));
        } catch (MalformedURLException e) {
            System.out.println(e.toString());
            return null;
        } catch (InterruptedException e) {
            System.out.println(e.toString());
            return null;
        }
        try {
            clocker.acquire(semaphorSize);
        } catch (InterruptedException e) {
            System.out.println(e.toString());
            return null;
        }
        return new Result(result.keySet().stream().collect(Collectors.toList()), errors);
    }

    @Override
    public void close() {
        downloadService.shutdown();
        extractService.shutdown();
        if (!downloadService.isShutdown()) {
            try {
                downloadService.awaitTermination(1, TimeUnit.SECONDS);
            } catch (InterruptedException e) {
                System.out.println(e.toString());
            } finally {
                downloadService.shutdownNow();
            }
        }
        if (!extractService.isShutdown()) {
            try {
                extractService.awaitTermination(1, TimeUnit.SECONDS);
            } catch (InterruptedException e) {
                System.out.println(e.toString());
            } finally {
                extractService.shutdownNow();
            }
        }
    }

    public static void main(String[] args) {
        for (int i = 0; i < 5; i++) {
            System.out.println(args[i]);
        }
        if (args == null || args.length == 0 || Arrays.stream(args).filter(a -> a == null).count() > 0) {
            System.out.println("Usage: WebCrawler url [dowloads [extractors [perHost]]]");
            return;
        }
        String url = args[0];
        int downloaders = 100;
        int extractors = 100;
        int perHost = 100;
        if (args.length > 1) {
            downloaders = Integer.parseInt(args[1]);
        }
        if (args.length > 2) {
            extractors = Integer.parseInt(args[2]);
        }
        if (args.length == 4) {
            perHost = Integer.parseInt(args[3]);
        }
        try (WebCrawler crawler = new WebCrawler(new CachingDownloader(), downloaders, extractors, perHost)) {
            Result result = crawler.download(url, args.length >= 5 ? Integer.parseInt(args[4]) : 1);
            for (IOException error : result.getErrors().values()) {
                System.out.println(error.toString());
            }
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }
}