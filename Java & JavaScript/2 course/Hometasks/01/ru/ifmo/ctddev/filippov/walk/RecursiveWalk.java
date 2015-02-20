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
            try (BufferedInputStream fileStream = new BufferedInputStream(new FileInputStream(new File(fileName)))) {
            int hash = x0;
                int c;
                while ((c = fileStream.read()) >= 0) {
                    hash = (hash * p) ^ c;
                }
                return hash;
            } catch (IOException e) {
                return 0;
            }
        }
    }
    
    public void run(String[] args) {
        if (args == null || args.length != 2) {
            System.out.println("Usage: java RecursiveWalk <input file> <output file>");
            return;
        }
        if (args[0] == null && args[1] == null) {
            System.out.println("Some arguments are equal null - very bad :(");
            return;
        }
        String inputFileName = args[0];
        String outputFileName = args[1];
        
        try (Scanner reader = new Scanner(new File(inputFileName), StandardCharsets.UTF_8.toString());
            final Writer writer = new OutputStreamWriter(new FileOutputStream(outputFileName), StandardCharsets.UTF_8.toString())) {
            while (reader.hasNextLine()) {
                Path start = Paths.get(reader.nextLine());
                try {
                    Files.walkFileTree(start, new SimpleFileVisitor<Path>() {
                        @Override
                        public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
                            String fileName = file.toString();
                            writer.write(String.format("%08x %s\n", FNVHasher.hashCode(fileName), fileName));
                            return FileVisitResult.CONTINUE;
                        }
                        
                        @Override
                        public FileVisitResult visitFileFailed(Path file, IOException e) throws IOException {
                            writer.write(String.format("%08x %s\n", 0, file.toString()));
                            return FileVisitResult.CONTINUE;
                        }
                        
                        @Override
                        public FileVisitResult postVisitDirectory(Path dir, IOException e) {
                            if (e == null) {
                                return FileVisitResult.CONTINUE;
                            } else {
                                return FileVisitResult.SKIP_SUBTREE;
                            }
                        }
                    });
                } catch (IOException e) {
                    System.out.println("IOException raised while walking throw file tree: " + e.getMessage());                
                }                
            }
        } catch (FileNotFoundException e) {
            System.out.println(e.toString());
            return;
        } catch (IOException e) {
            System.out.println(e.toString());
            return;
        }
    }
    
    public static void main(String[] args) {
        new RecursiveWalk().run(args);
    }
}
