#!/bin/bash
cd src
rm -rf javadoc
mkdir javadoc
javadoc -d javadoc -linkoffline http://docs.oracle.com/javase/8/docs/api/ http://docs.oracle.com/javase/8/docs/api/ info/kgeorgiy/java/advanced/concurrent/{ListIP,ScalarIP}.java ru/ifmo/ctddev/filippov/iterativeparallelism/{IterativeParallelism,Monoid,IterativeParallelismUtils}.java