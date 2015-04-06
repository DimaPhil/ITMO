#!/bin/sh
cd src
javac -cp .:../lib/* ru/ifmo/ctddev/filippov/parallelmapper/ParallelMapperImpl.java
javac -cp .:../lib/* ru/ifmo/ctddev/filippov/parallelmapper/IterativeParallelism.java
java -cp .:../lib/* info.kgeorgiy.java.advanced.mapper.Tester list ru.ifmo.ctddev.filippov.parallelmapper.ParallelMapperImpl,ru.ifmo.ctddev.filippov.parallelmapper.IterativeParallelism