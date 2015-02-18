package ru.ifmo.ctddev.filippov.walk;

import java.io.*;
import java.util.*;
import java.nio.charset.*;
import java.nio.file.*;
import java.nio.file.attribute.*;

public class RecursiveWalk {
    private static class FNVHasher {
        private static final int p = 16777619;
        private static final int x0 = (int)2166136261L;
        
        public static int hashCode(String fileName) throws FileNotFoundException {
            FileInputStream fileStream = new FileInputStream(new File(fileName));
            int hash = x0;
            try {
                int c;
                while ((c = fileStream.read()) >= 0) {
                    hash = (hash * p) ^ c;
                }
            } catch (IOException e) {
                return 0;
            }
            return hash;
        }
    }
    
    public void run(String[] args) {
        if (args.length < 2) {
            System.out.println("Not enough arguments - need 2, found " + args.length);
            return;
        }
        String inputFile = args[0];
        String outputFile = args[1];
        
        try (Scanner reader = new Scanner(new File(inputFile), StandardCharsets.UTF_8.toString());
            final Writer writer = new OutputStreamWriter(new FileOutputStream(outputFile), StandardCharsets.UTF_8.toString())) {
            while (reader.hasNextLine()) {
                Path start = Paths.get(reader.nextLine());
                if (!Files.exists(start)) {
                    writer.write(String.format("00000000 %s\n", start.toString()));
                    continue;
                }
                try {
                    Files.walkFileTree(start, new SimpleFileVisitor<Path>() {
                        @Override
                        public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
                            String fileName = file.toString();
                            writer.write(String.format("%08x %s\n", FNVHasher.hashCode(fileName), fileName));
                            return FileVisitResult.CONTINUE;
                        }
                        
                        @Override
                        public FileVisitResult postVisitDirectory(Path dir, IOException e) throws IOException {
                            if (e == null) {
                                return FileVisitResult.CONTINUE;
                            } else {
                                return FileVisitResult.SKIP_SUBTREE;
                            }
                        }
                    });
                } catch (IOException e) {
                    e.printStackTrace();
                }                
            }
        } catch (FileNotFoundException e) {
            System.out.println("No such input file: " + inputFile);
            return;
        } catch (IOException e) {
            System.out.println("Can\'t close output file");
            return;
        }
    }
    
    public static void main(String[] args) {
        new RecursiveWalk().run(args);
    }
}
