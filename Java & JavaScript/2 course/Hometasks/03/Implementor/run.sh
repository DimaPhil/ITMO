#!/bin/sh
cd src
javac -cp .:../lib/Implementor.jar ru/ifmo/ctddev/filippov/implementor/Implementor.java
java -cp ../lib/ImplementorTest.jar:.:../lib/junit-4.11.jar:../lib/hamcrest-core-1.3.jar:../lib/quickcheck-0.6.jar info.kgeorgiy.java.advanced.implementor.Tester class ru.ifmo.ctddev.filippov.implementor.Implementor
