package ru.ifmo.ctddev.filippov.hello;

import info.kgeorgiy.java.advanced.hello.HelloServer;

import java.io.IOException;
import java.net.*;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicBoolean;

public class HelloUDPServer implements HelloServer {
    private ConcurrentHashMap<Integer, AtomicBoolean> running = new ConcurrentHashMap<>();
    private ConcurrentHashMap<Integer, ExecutorService> pools = new ConcurrentHashMap<>();
    private ConcurrentHashMap<Integer, DatagramSocket> socket = new ConcurrentHashMap<>();

    @Override
    public synchronized void start(int port, int threads) {
        if (!running.contains(port)) {
            running.put(port, new AtomicBoolean(false));
        }
        if (running.get(port).get()) {
            throw new IllegalStateException("Can't run server that is already started");
        }
        pools.put(port, Executors.newFixedThreadPool(threads));
        try {
            socket.put(port, new DatagramSocket(port, InetAddress.getByName("localhost")));
            socket.get(port).setSoTimeout(100);
            for (int i = 0; i < threads; i++) {
                final int threadId = i;
                pools.get(port).submit(() -> {
                    try {
                        byte[] buffer = new byte[socket.get(port).getSendBufferSize()];
                        DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
                        while (running.get(port).get()) {
                            try {
                                socket.get(port).receive(packet);
                                byte[] data = packet.getData();
                                String result = new String(data, 0, packet.getLength());
                                String replyText = "Hello, " + result;
                                DatagramPacket reply = new DatagramPacket(
                                        replyText.getBytes(),
                                        replyText.getBytes().length,
                                        packet.getAddress(),
                                        packet.getPort()
                                );
                                socket.get(port).send(reply);
                            } catch (SocketTimeoutException ignored) {
                            }
                        }
                    } catch (IOException e) {
                        System.out.println("SERVER: fatal error thread #" + threadId);
                        System.out.println(e.toString());
                    }
                });
            }
            running.get(port).set(true);
        } catch (SocketException | UnknownHostException e) {
            System.out.println(e.toString());
        }
    }

    @Override
    public synchronized void close() {
        for (int port : running.keySet()) {
            if (!running.get(port).get()) {
                continue;
            }
            running.get(port).set(false);
            pools.get(port).shutdown();
            pools.get(port).shutdownNow();
        }
    }

    public static void main(String[] args) {
        try {
            HelloUDPServer server = new HelloUDPServer();
            int port = Integer.parseInt(args[0]);
            int threads = Integer.parseInt(args[1]);
            server.start(port, threads);
            HelloUDPClient client = new HelloUDPClient();
            client.start("localhost", port, "prefix", 10, 10);
        } catch (NumberFormatException e) {
            System.out.println("Usage: java HelloUDPServer [port] [threads]");
        }
    }
}