#!/bin/sh
cd src
javac -cp .:../lib/* ru/ifmo/ctddev/filippov/hello/HelloUDPClient.java
javac -cp .:../lib/* ru/ifmo/ctddev/filippov/hello/HelloUDPServer.java
#java -cp .:../lib/* info.kgeorgiy.java.advanced.hello.Tester client ru.ifmo.ctddev.filippov.hello.HelloUDPClient
java -cp .:../lib/* info.kgeorgiy.java.advanced.hello.Tester server ru.ifmo.ctddev.filippov.hello.HelloUDPServer
