#!/bin/bash
cd src
rm -rf javadoc
mkdir javadoc
javadoc -d javadoc -linkoffline http://docs.oracle.com/javase/8/docs/api/ http://docs.oracle.com/javase/8/docs/api/ -private info/kgeorgiy/java/advanced/implementor/{Impler,JarImpler,ImplerException}.java ru/ifmo/ctddev/filippov/implementor/Implementor.java