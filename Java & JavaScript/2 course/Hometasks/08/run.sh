#!/bin/sh
cd src
javac -cp .:../lib/* ru/ifmo/ctddev/filippov/crawler/WebCrawler.java
java -cp .:../lib/* info.kgeorgiy.java.advanced.crawler.Tester hard ru.ifmo.ctddev.filippov.crawler.WebCrawler