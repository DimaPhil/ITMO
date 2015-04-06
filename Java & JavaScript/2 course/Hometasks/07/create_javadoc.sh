#!/bin/bash
cd src
rm -rf javadoc
mkdir javadoc
javadoc -d javadoc -linkoffline http://docs.oracle.com/javase/8/docs/api/ http://docs.oracle.com/javase/8/docs/api/ ru/ifmo/ctddev/filippov/parallelmapper/{IterativeParallelism,Monoid,IterativeParallelismUtils,ParallelMapperImpl}.java