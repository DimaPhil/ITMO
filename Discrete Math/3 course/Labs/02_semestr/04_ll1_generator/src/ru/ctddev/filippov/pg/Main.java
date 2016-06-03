package ru.ctddev.filippov.pg;

import java.io.File;
import java.io.IOException;

public class Main {
    private static final String PATH = "grammars/PascalBoolExpression.txt";

    public static void main(String[] args) throws IOException {
        System.out.println("Current directory: " + System.getProperty("user.dir"));
        Generator generator = new Generator(new File(PATH));
        generator.generateFiles();
    }
}
