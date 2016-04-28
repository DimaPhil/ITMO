package ru.ifmo.ctddev.filippov.parser;

import javax.swing.*;
import java.awt.*;

/**
 * Created by dmitry on 27.04.16.
 */
public class Visualizer {
    private class TreeJFrame extends JFrame {
        private Tree tree;
        public TreeJFrame(Tree tree) {
            this.tree = tree;

            setContentPane(new TreePanel());
            setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
            setSize(1000, 700);
            setVisible(true);
        }


        private class TreePanel extends JPanel {
            @Override
            public void paintComponent(Graphics g) {
                tree.draw(g, new int[]{0, 1000}, 10);
            }
        }
    }

    public void visualize(Tree root) {
        new TreeJFrame(root);
    }
}
