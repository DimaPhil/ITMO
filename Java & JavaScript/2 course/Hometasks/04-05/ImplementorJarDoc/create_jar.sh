#!/bin/bash
cd src
rm -rf META-INF
mkdir META-INF
echo Manifest-Version: 1.0> META-INF/manifest.1
echo Main-Class: ru.ifmo.ctddev.filippov.implementor.Implementor> META-INF/manifest.1
javac -cp .:../lib/ImplementorTest.jar ru/ifmo/ctddev/filippov/implementor/Implementor.java
jar -cfm Implementor.jar META-INF/manifest.1 ru/ifmo/ctddev/filippov/implementor/Implementor.class