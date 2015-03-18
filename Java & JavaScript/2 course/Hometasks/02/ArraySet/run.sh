#!/bin/sh
cd src
javac ru/ifmo/ctddev/filippov/arrayset/ArraySet.java
java -cp ../ArraySetTest.jar:.:../junit-4.11.jar:../hamcrest-core-1.3.jar:../quickcheck-0.6.jar info.kgeorgiy.java.advanced.arrayset.Tester NavigableSet ru.ifmo.ctddev.filippov.arrayset.ArraySet
