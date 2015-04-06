package ru.ifmo.ctddev.filippov.iterativeparallelism;

import java.util.ArrayList;
import java.util.Random;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        IterativeParallelism parallelism = new IterativeParallelism();
        ArrayList<String> strings = new ArrayList<>();
        Random rand = new Random(7391873987192837L);
        //for (int i = 0; i < 100; i++) {
        //    strings.add(String.valueOf(rand.nextInt(10000)));
        //}
        strings.add("lol1");
        strings.add("lol2");
        strings.add("lol3");
        strings.add("lol4");
        System.out.println(parallelism.concat(3, strings));
    }
}
