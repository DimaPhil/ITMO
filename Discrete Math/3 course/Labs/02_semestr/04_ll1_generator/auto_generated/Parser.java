import java.io.*;
import java.util.*;

import java.awt.*;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;


public class Parser{

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

        private static final int width = 110;
        private static final int height = 15;

        int[] draw(Graphics g, int x[], int y) {
            List<Integer> cx = new ArrayList<>();
            List<Integer> cy = new ArrayList<>();

            for (Tree child : children) {
                if (child == null) {
                    continue;
                }
                int[] result = child.draw(g, x, y + 30);
                cx.add(result[0]);
                cy.add(result[1]);
            }

            int wx, wy;
            if (cx.isEmpty()) {
                wx = x[0];
                wy = y;
                x[0] += 110;
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

    private LexicalAnalyzer analyzer;

    public Tree parse(InputStream is) throws ParseException {
        analyzer = new LexicalAnalyzer(is);
        analyzer.nextToken();
        return pascal_expression();
    }

    private Tree expression() throws ParseException {
        HashMap<String, Object> results = new HashMap<>();
        switch (analyzer.getCurToken()) {

            case NOT:
                results.put("summand", summand());
                results.put("expression_prime", expression_prime());
                return new Tree("expression", (Tree) results.get("summand"), (Tree) results.get("expression_prime")); 
            case OR:
            case VAR:
                results.put("summand", summand());
                results.put("expression_prime", expression_prime());
                return new Tree("expression", (Tree) results.get("summand"), (Tree) results.get("expression_prime")); 
            case AND:
            case RIGHT_PAREN:
            case XOR:
            case END:
            case LEFT_PAREN:
                results.put("summand", summand());
                results.put("expression_prime", expression_prime());
                return new Tree("expression", (Tree) results.get("summand"), (Tree) results.get("expression_prime")); 
            default:
                throw new ParseException("Incorrect token at expression(): " + analyzer.getCurToken());
        }
    }
    private Tree summand() throws ParseException {
        HashMap<String, Object> results = new HashMap<>();
        switch (analyzer.getCurToken()) {

            case NOT:
                results.put("and", and());
                results.put("summand_prime", summand_prime());
                return new Tree("summand", (Tree) results.get("and"), (Tree) results.get("summand_prime")); 
            case OR:
            case VAR:
                results.put("and", and());
                results.put("summand_prime", summand_prime());
                return new Tree("summand", (Tree) results.get("and"), (Tree) results.get("summand_prime")); 
            case AND:
            case RIGHT_PAREN:
            case XOR:
            case END:
            case LEFT_PAREN:
                results.put("and", and());
                results.put("summand_prime", summand_prime());
                return new Tree("summand", (Tree) results.get("and"), (Tree) results.get("summand_prime")); 
            default:
                throw new ParseException("Incorrect token at summand(): " + analyzer.getCurToken());
        }
    }
    private Tree pascal_expression() throws ParseException {
        HashMap<String, Object> results = new HashMap<>();
        switch (analyzer.getCurToken()) {

            case NOT:
                results.put("expression", expression());
                results.put("pascal_expression", new Tree("pascal_expression", (Tree) results.get("expression")));
 return (Tree) results.get("pascal_expression"); 
            case OR:
            case VAR:
                results.put("expression", expression());
                results.put("pascal_expression", new Tree("pascal_expression", (Tree) results.get("expression")));
 return (Tree) results.get("pascal_expression"); 
            case AND:
            case RIGHT_PAREN:
            case XOR:
            case END:
            case LEFT_PAREN:
                results.put("expression", expression());
                results.put("pascal_expression", new Tree("pascal_expression", (Tree) results.get("expression")));
 return (Tree) results.get("pascal_expression"); 
            default:
                throw new ParseException("Incorrect token at pascal_expression(): " + analyzer.getCurToken());
        }
    }
    private Tree and() throws ParseException {
        HashMap<String, Object> results = new HashMap<>();
        switch (analyzer.getCurToken()) {

            case NOT:
                if (analyzer.getCurToken() != Token.NOT) {
                    throw new ParseException(") expected at position " + analyzer.getCurPos(), analyzer.getCurPos());
                }
                analyzer.nextToken();
                results.put("and", and());
                return new Tree("and", new Tree("NOT"), (Tree) results.get("and")); 
            case OR:
            case VAR:
                if (analyzer.getCurToken() != Token.VAR) {
                    throw new ParseException(") expected at position " + analyzer.getCurPos(), analyzer.getCurPos());
                }
                analyzer.nextToken();
                return new Tree("and", new Tree("VAR")); 
            case AND:
            case RIGHT_PAREN:
            case XOR:
            case END:
            case LEFT_PAREN:
                if (analyzer.getCurToken() != Token.LEFT_PAREN) {
                    throw new ParseException(") expected at position " + analyzer.getCurPos(), analyzer.getCurPos());
                }
                analyzer.nextToken();
                results.put("expression", expression());
                if (analyzer.getCurToken() != Token.RIGHT_PAREN) {
                    throw new ParseException(") expected at position " + analyzer.getCurPos(), analyzer.getCurPos());
                }
                analyzer.nextToken();
                return new Tree("and", new Tree("("), (Tree) results.get("expression"), new Tree(")")); 
            default:
                throw new ParseException("Incorrect token at and(): " + analyzer.getCurToken());
        }
    }
    private Tree summand_prime() throws ParseException {
        HashMap<String, Object> results = new HashMap<>();
        switch (analyzer.getCurToken()) {

            case NOT:
            case OR:
            return null;

            case VAR:
            case AND:
                if (analyzer.getCurToken() != Token.AND) {
                    throw new ParseException(") expected at position " + analyzer.getCurPos(), analyzer.getCurPos());
                }
                analyzer.nextToken();
                results.put("and", and());
                results.put("summand_prime", summand_prime());
                return new Tree("summand_prime", new Tree("AND"), (Tree) results.get("and"), (Tree) results.get("summand_prime")); 
            case RIGHT_PAREN:
            return null;

            case XOR:
            return null;

            case END:
            return null;

            case LEFT_PAREN:
            default:
                throw new ParseException("Incorrect token at summand_prime(): " + analyzer.getCurToken());
        }
    }
    private Tree expression_prime() throws ParseException {
        HashMap<String, Object> results = new HashMap<>();
        switch (analyzer.getCurToken()) {

            case NOT:
            case OR:
                if (analyzer.getCurToken() != Token.OR) {
                    throw new ParseException(") expected at position " + analyzer.getCurPos(), analyzer.getCurPos());
                }
                analyzer.nextToken();
                results.put("summand", summand());
                results.put("expression_prime", expression_prime());
                return new Tree("expression_prime", new Tree("OR"), (Tree) results.get("summand"), (Tree) results.get("expression_prime")); 
            case VAR:
            case AND:
            case RIGHT_PAREN:
            return null;

            case XOR:
                if (analyzer.getCurToken() != Token.XOR) {
                    throw new ParseException(") expected at position " + analyzer.getCurPos(), analyzer.getCurPos());
                }
                analyzer.nextToken();
                results.put("summand", summand());
                results.put("expression_prime", expression_prime());
                return new Tree("expression_prime", new Tree("XOR"), (Tree) results.get("summand"), (Tree) results.get("expression_prime")); 
            case END:
            return null;

            case LEFT_PAREN:
            default:
                throw new ParseException("Incorrect token at expression_prime(): " + analyzer.getCurToken());
        }
    }
}
