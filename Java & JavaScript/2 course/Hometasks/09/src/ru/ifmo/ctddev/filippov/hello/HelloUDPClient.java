package ru.ifmo.ctddev.filippov.hello;

import info.kgeorgiy.java.advanced.hello.HelloClient;

import java.io.IOException;
import java.net.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicInteger;

public class HelloUDPClient implements HelloClient {
    private class ClientException extends Exception {
        public ClientException(String message) {
            super(message);
        }
    }

    @Override
    public void start(String host, int port, String prefix, int requests, int threads) {
        ExecutorService threadPool = Executors.newFixedThreadPool(threads);
        AtomicInteger threadsLeft = new AtomicInteger(threads);
        try {
            Semaphore semaphore = new Semaphore(threads + 1);
            semaphore.acquire();
            final InetAddress address = InetAddress.getByName(host);
            for (int i = 0; i < threads; i++) {
                final int finalThreadId = i;
                threadPool.submit(() -> {
                    try {
                        semaphore.acquire();
                        try (final DatagramSocket socket = new DatagramSocket()) {
                            socket.setSoTimeout(100);
                            byte[] buffer = new byte[socket.getReceiveBufferSize()];
                            int currentRequest = 0;
                            while (currentRequest != requests) {
                                String message = (prefix + finalThreadId + "_" + currentRequest);
                                byte[] messageBytes = message.getBytes();
                                System.out.println(message);
                                socket.send(new DatagramPacket(messageBytes, messageBytes.length, address, port));

                                DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
                                try {
                                    socket.receive(reply);
                                    byte[] data = reply.getData();
                                    String response = new String(data, 0, reply.getLength());
                                    if (!response.equals("Hello, " + message)) {
                                        throw new ClientException("wrong response");
                                    }
                                    String[] splitedResponse = response.split("_");
                                    int requestId = Integer.parseInt(splitedResponse[splitedResponse.length - 1]);
                                    if (requestId >= requests) {
                                        throw new ClientException("wrong request id");
                                    }
                                    System.out.println(response);
                                    currentRequest++;
                                } catch (SocketTimeoutException | ClientException e) {
                                    // ok, we'll resend socket
                                }
                            }
                        } catch (IOException e) {
                        }
                        semaphore.release();
                        if (semaphore.availablePermits() == threads) {
                            System.err.println("releasing the last semaphore entry");
                            semaphore.release();
                        }
                    } catch (InterruptedException e) {
                        return;
                    }
                    System.err.println("Client #" + finalThreadId + " will shutdown now");
                    threadsLeft.decrementAndGet();
                    if (threadsLeft.get() == 0) {
                        System.err.println("Client #" + finalThreadId + " shutting down the pool");
                        threadPool.shutdownNow();
                    }
                    System.err.println("Client #" + finalThreadId + " is out");
                });
            }
            Thread.sleep(100);
            semaphore.acquire(threads + 1);
        } catch (UnknownHostException | InterruptedException e) {
            System.out.println(e.toString());
        }
    }

    public static void main(String[] args) {
        if (args == null || args.length != 5) {
            System.out.println("Usage: java HelloUDPClient [host] [port] [prefix] [requests] [threads]");
        }
        String host = args[0];
        int port = Integer.parseInt(args[1]);
        String prefix = args[2];
        int requests = Integer.parseInt(args[3]);
        int threads = Integer.parseInt(args[4]);

        HelloUDPClient client = new HelloUDPClient();
        client.start(host, port, prefix, requests, threads);
    }
}