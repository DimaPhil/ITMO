import javax.swing.*;
import java.awt.*;

public class Visualizer {
    private class TreeJFrame extends JFrame {
        private Parser.Tree tree;
        public TreeJFrame(Parser.Tree tree) {
            this.tree = tree;

            setContentPane(new TreePanel());
            setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
            setSize(1300, 700);
            setVisible(true);
        }


        private class TreePanel extends JPanel {
            @Override
            public void paintComponent(Graphics g) {
                tree.draw(g, new int[]{0, 1000}, 10);
            }
        }
    }

    public void visualize(Parser.Tree root) {
        new TreeJFrame(root);
    }
}