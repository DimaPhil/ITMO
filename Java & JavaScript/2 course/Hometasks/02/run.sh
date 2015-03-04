#!/bin/sh
cd src
javac ArraySet.java
java -cp ../ArraySetTest.jar:.:../junit-4.11.jar:../hamcrest-core-1.3.jar:../quickcheck-0.6.jar info.kgeorgiy.java.advanced.arrayset.Tester NavigableSet ArraySet
