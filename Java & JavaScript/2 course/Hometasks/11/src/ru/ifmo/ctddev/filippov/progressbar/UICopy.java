package ru.ifmo.ctddev.filippov.progressbar;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.nio.file.*;
import java.nio.file.attribute.BasicFileAttributes;

public class UICopy implements ActionListener {
    private Path fromPath, toPath;
    private JFrame frame;
    private JPanel panel;
    private JPanel statusPanel;
    private JLabel title;
    private JProgressBar progressBar;
    private JButton cancelButton;
    private int copiedFiles, allFiles;

    public UICopy(String from, String to) {
        fromPath = Paths.get(from);
        toPath = Paths.get(to);
        allFiles = 0;
        UIFileVisitor visitor = new UIFileVisitor();
        visitor.countFiles(fromPath);

        frame = new JFrame("UICopy");
        frame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);

        try {
          UIManager.setLookAndFeel("javax.swing.plaf.nimbus.NimbusLookAndFeel");
        } catch (ClassNotFoundException | UnsupportedLookAndFeelException | InstantiationException | IllegalAccessException e) {
            System.out.println(e.toString());
        }

        panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));

        title = new JLabel("Copying..., 0/" + allFiles + " done");
        title.setAlignmentX(Component.CENTER_ALIGNMENT);
        title.setBorder(new EmptyBorder(5, 5, 5, 5));

        progressBar = new JProgressBar(0, 100);

        statusPanel = new JPanel();
        statusPanel.setLayout(new GridLayout(2, 2, 5, 5));

        cancelButton = new JButton("Cancel");
        cancelButton.addActionListener(this);
        cancelButton.setActionCommand("cancel");
        cancelButton.setAlignmentX(Component.CENTER_ALIGNMENT);

        panel.setBorder(new EmptyBorder(100, 100, 100, 100));
        panel.add(title);
        panel.add(progressBar);
        panel.add(statusPanel);
        panel.add(cancelButton);

        frame.setContentPane(panel);
    }

    void run() {
        frame.pack();
        frame.setVisible(true);
        UIFileVisitor visitor = new UIFileVisitor();
        visitor.copy(fromPath, toPath);
    }

    public static void main(String[] args) {
        args = new String[]{"../../IdeaProjects", "B"};
        UICopy copier = new UICopy(args[0], args[1]);
        copier.run();
    }

    @Override
    public void actionPerformed(ActionEvent event) {
        if (event.getActionCommand().equals("cancel")) {
            /*JPanel panel1 = new JPanel();
            panel1.add(new JButton("Yes"));
            panel1.add(new JButton("No"));
            JLabel title = new JLabel("Are you sure?");
            title.setAlignmentX(Component.CENTER_ALIGNMENT);
            panel1.add(title);
            frame.setContentPane(panel1);
            frame.setVisible(true);*/
            System.exit(0);
        }
    }

    private class UIFileVisitor {
        public void countFiles(Path start) {
            try {
                Files.walkFileTree(start, new SimpleFileVisitor<Path>() {
                    @Override
                    public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
                        ++allFiles;
                        return FileVisitResult.CONTINUE;
                    }

                    @Override
                    public FileVisitResult visitFileFailed(Path file, IOException e) throws IOException {
                        ++allFiles;
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
                System.out.println("IOException raised while walking throw file tree: " + e.toString());
            }
        }

        private void copyFile(Path destination, String fileName) {
            if (Files.exists(destination)) {
                try {
                    Files.delete(destination);
                } catch (IOException e) {
                    System.out.println("Cannot remove and overwrite file, that exists");
                }
            }
            try {
                Files.copy(Paths.get(fileName), destination);
                ++copiedFiles;
                title.setText("Copying..., " + copiedFiles + "/" + allFiles + " done");
                progressBar.setValue((int)(copiedFiles * 100.f / allFiles));
                if (copiedFiles == allFiles) {
                    JOptionPane.showMessageDialog(frame, "All files were copied!");
                }
            } catch (IOException e) {
                System.out.println("Cannot copy file " + fileName + ": " + e.toString());
            }
        }

        public void copy(Path start, final Path destination) {
            try {
                Files.walkFileTree(start, new SimpleFileVisitor<Path>() {
                    @Override
                    public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
                        String fileName = file.toString();
                        copyFile(destination, fileName);
                        return FileVisitResult.CONTINUE;
                    }

                    @Override
                    public FileVisitResult visitFileFailed(Path file, IOException e) throws IOException {
                        copyFile(destination, file.toString());
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
                System.out.println("IOException raised while walking throw file tree: " + e.toString());
            }
        }
    }
}
