package ru.ifmo.ctddev.filippov.parser;

import java.awt.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by dmitry on 23.03.16.
 */
public class Tree {
    String node;
    List<Tree> children = new ArrayList<>();

    public Tree(String node, Tree... children) {
        this.node = node;
        this.children = Arrays.asList(children);
    }

    public Tree(String node) {
        this.node = node;
    }

    private static final int width = 70;
    private static final int height = 15;

    int[] draw(Graphics g, int x[], int y) {
        List<Integer> cx = new ArrayList<>();
        List<Integer> cy = new ArrayList<>();

        for (Tree child : children) {
            int[] result = child.draw(g, x, y + 30);
            cx.add(result[0]);
            cy.add(result[1]);
        }

        int wx, wy;
        if (cx.isEmpty()) {
            wx = x[0];
            wy = y;
            x[0] += 80;
        } else {
            wx = (cx.get(0) + cx.get(cx.size() - 1) - width) / 2;
            wy = y;
        }
        g.drawRect(wx, wy, width, height);
        if (cx.isEmpty()) {
            g.setColor(Color.green);
            g.fillRect(wx, wy, width, height);
            g.setColor(Color.BLACK);
        }
        g.drawString(node, wx + 3, wy + height - 3);
        for (int i = 0; i < cx.size(); i++) {
            g.drawLine(wx + width / 2, wy + height, cx.get(i), cy.get(i));
        }
        return new int[]{wx + width / 2, wy};
    }
}
