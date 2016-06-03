package ru.ctddev.filippov.pg;

import org.antlr.v4.runtime.ANTLRInputStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.TerminalNode;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

class Generator {
    private class Pair<F, S> {

        final F fst;
        final S snd;

        Pair(F fst, S snd) {
            this.fst = fst;
            this.snd = snd;
        }

        private boolean equals(Object x, Object y) {
            return (x == null && y == null) || (x != null && x.equals(y));
        }

        @Override
        public boolean equals(Object other) {
            return (other instanceof Pair &&
                    equals(fst, ((Pair)other).fst) &&
                    equals(snd, ((Pair)other).snd));
        }

        @Override
        public int hashCode() {
            if (fst == null) {
                return (snd == null) ? 0 : snd.hashCode() + 1;
            }
            if (snd == null) {
                return fst.hashCode() + 19;
            }
            return fst.hashCode() * 239 + snd.hashCode();
        }
    }

    private static final String AUTO_GENERATED_PATH = "auto_generated";
    private static final String PARSER_NAME = "Parser";
    private static final String LEXER_NAME = "LexicalAnalyzer";
    private static final String TOKEN_FILE_NAME = "Token";
    private static final String EXCEPTION_NAME = "ParseException";
    private static final String EPS_NODE_NAME = "EPS";
    private static final String END_NODE_NAME = "END";
    private static final String END_MARKER = "$";

    private File file;

    private NonTermNode start;
    private final HashMap<String, NonTermNode> nonTerminals = new HashMap<>();
    private final HashMap<String, TermNode> terminals = new HashMap<>();
    private final HashMap<Node, HashSet<TermNode>> first = new HashMap<>();
    private final HashMap<NonTermNode, HashSet<TermNode>> follow = new HashMap<>();
    private final HashMap<Pair<NonTermNode, TermNode>, Derivation> predictionTable = new HashMap<>();
    private String header = "";
    private String members = "";


    Generator(File file) {
        this.file = file;
    }

    void generateFiles() throws IOException {
        InputStream is = new FileInputStream(file);
        ANTLRInputStream input = new ANTLRInputStream(is);
        GrammarLexer lexer = new GrammarLexer(input);
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        GrammarParser parser = new GrammarParser(tokens);
        GrammarVisitor<Object> visitor = new GrammarBaseVisitor<Object>() {
            @Override
            public Object visitNonTermLabel(GrammarParser.NonTermLabelContext ctx) {
                String name = ctx.NON_TERM_NAME().getText();
                NonTermNode curNode = getNonTerminalNode(name);
                if (start == null) {
                    start = curNode;
                }
                List<Derivation> productions = new ArrayList<>();

                if (ctx.declRet() != null) {
                    curNode.setReturnType(ctx.declRet().type().getText());
                }
                for (GrammarParser.NonTermProductionContext nonTermProductionContext : ctx.nonTermProduction()) {
                    Derivation production = new Derivation();
                    if (nonTermProductionContext.JAVACODE() != null) {
                        production.setSymbol(removeFirstCharacter(nonTermProductionContext.JAVACODE().getText()));
                    }

                    if (nonTermProductionContext.nodeNonTermProduction().isEmpty()) {
                        TermNode node = getTerminalNode(EPS_NODE_NAME);
                        node.addProduction("");
                        production.addNode(node);
                    }

                    for (GrammarParser.NodeNonTermProductionContext node : nonTermProductionContext.nodeNonTermProduction()) {
                        production.addNode(node.NON_TERM_NAME() != null ? getNonTerminalNode(node.NON_TERM_NAME().getText())
                            : getTerminalNode(node.TERM_NAME().getText()));
                    }
                    productions.add(production);
                }
                curNode.addProductionsList(productions);
                return super.visitNonTermLabel(ctx);
            }


            @Override
            public Object visitTermLabel(GrammarParser.TermLabelContext ctx) {
                String name = ctx.TERM_NAME().getText();
                TermNode curNode = getTerminalNode(name);
                for (GrammarParser.TermProductionContext term_productionContext : ctx.termProduction()) {
                    for (TerminalNode node : term_productionContext.NON_TERM_NAME()) {
                        curNode.addProduction(node.getText());
                    }
                    for (TerminalNode node : term_productionContext.LEFT_PAREN()) {
                        curNode.addProduction(node.getText());
                    }
                    for (TerminalNode node : term_productionContext.RIGHT_PAREN()) {
                        curNode.addProduction(node.getText());
                    }
                }
                return super.visitTermLabel(ctx);
            }

            @Override
            public Object visitHeaderLabel(GrammarParser.HeaderLabelContext ctx) {
                header = removeFirstCharacter(ctx.JAVACODE().getText());
                return super.visitHeaderLabel(ctx);
            }

            @Override
            public Object visitMembersLabel(GrammarParser.MembersLabelContext ctx) {
                members = removeFirstCharacter(ctx.JAVACODE().getText());
                return super.visitMembersLabel(ctx);
            }
        };
        visitor.visit(parser.main());
        TermNode endNode = getTerminalNode(END_NODE_NAME);
        endNode.addProduction(END_MARKER);
        terminals.put(END_NODE_NAME, endNode);

        cleanGenerateDirectory();
        generateExceptionFile();
        generateTokenFile();
        computeFirst();
        computeFollow();
        computeTable();
        generateLexer();
        generateParser();
    }


    private TermNode getTerminalNode(String name) {
        if (!terminals.containsKey(name)) {
            terminals.put(name, new TermNode(name));
        }
        return terminals.get(name);
    }

    private NonTermNode getNonTerminalNode(String name) {
        if (!nonTerminals.containsKey(name)) {
            nonTerminals.put(name, new NonTermNode(name));
        }
        return nonTerminals.get(name);
    }

    private void computeTable() {
        for (String name : nonTerminals.keySet()) {
            for (Derivation production : nonTerminals.get(name).getProductions()) {
                boolean fail = false;
                for (int i = 0; i < production.size(); i++) {
                    if (!first.get(production.getNode(i)).contains(getTerminalNode(EPS_NODE_NAME))) {
                        fail = true;
                        break;
                    }
                }
                if (!fail) {
                    for (TermNode node : follow.get(nonTerminals.get(name))) {
                        predictionTable.put(new Pair<>(nonTerminals.get(name), node), production);
                    }
                }
            }
        }

    }

    private void computeFirst() {
        for (String name : terminals.keySet()) {
            HashSet<TermNode> curFirstSet = new HashSet<>();
            curFirstSet.add(terminals.get(name));
            first.put(terminals.get(name), curFirstSet);
        }
        for (String name : nonTerminals.keySet()) {
            first.put(nonTerminals.get(name), new HashSet<>());
        }

        while (true) {
            boolean foundPrediction = false;
            for (String name : nonTerminals.keySet()) {
                for (Derivation production : nonTerminals.get(name).getProductions()) {
                    for (int i = 0; i < production.size(); i++) {
                        boolean fail = false;
                        for (int j = 0; j < i; j++) {
                            if (!first.get(production.getNode(j)).contains(getTerminalNode(EPS_NODE_NAME))) {
                                fail = true;
                                break;
                            }
                        }
                        if (!fail) {
                            for (TermNode cur : first.get(production.getNode(i))) {
                                if (!first.get(nonTerminals.get(name)).contains(cur)) {
                                    first.get(nonTerminals.get(name)).add(cur);
                                    predictionTable.put(new Pair<>(nonTerminals.get(name), cur), production);
                                    foundPrediction = true;
                                }
                            }
                        }
                    }

                }
            }
            if (!foundPrediction) {
                break;
            }
        }
    }

    private void computeFollow() {
        for (String name : nonTerminals.keySet()) {
            follow.put(nonTerminals.get(name), new HashSet<>());
        }
        follow.get(start).add(getTerminalNode(END_NODE_NAME));
        while (true) {
            boolean foundPrediction = false;
            for (String terminalName : nonTerminals.keySet()) {
                for (Derivation derivation : nonTerminals.get(terminalName).getProductions()) {
                    for (int i = 0; i < derivation.size(); i++) {
                        if (!derivation.getNode(i).isTerminal()) {
                            for (int j = i + 1; j < derivation.size(); j++) {
                                boolean fail = false;
                                for (int k = i + 1; k < j; k++) {
                                    if (!first.get(derivation.getNode(k)).contains(getTerminalNode(EPS_NODE_NAME))) {
                                        fail = true;
                                        break;
                                    }
                                }
                                if (!fail) {
                                    for (TermNode cur : first.get(derivation.getNode(j))) {
                                        NonTermNode node = (NonTermNode) derivation.getNode(i);
                                        if (!cur.name.equals(EPS_NODE_NAME) && !follow.get(node).contains(cur)) {
                                            follow.get(node).add(cur);
                                            foundPrediction = true;
                                        }
                                    }
                                }

                            }
                            boolean fail = false;
                            for (int j = i + 1; j < derivation.size(); j++) {
                                if (!first.get(derivation.getNode(j)).contains(getTerminalNode(EPS_NODE_NAME))) {
                                    fail = true;
                                    break;
                                }
                            }
                            if (!fail) {
                                for (TermNode cur : follow.get(nonTerminals.get(terminalName))) {
                                    NonTermNode node = (NonTermNode) derivation.getNode(i);
                                    if (!cur.name.equals(EPS_NODE_NAME) && !follow.get(node).contains(cur)) {
                                        follow.get(node).add(cur);
                                        foundPrediction = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (!foundPrediction) {
                break;
            }
        }
    }

    private void generateExceptionFile() throws IOException {
        File file = new File(AUTO_GENERATED_PATH, EXCEPTION_NAME + ".java");
        if (!file.createNewFile()) {
            System.err.println("Can't create file " + file.toString());
        }
        PrintWriter out = new PrintWriter(file);
        out.println("public class " + EXCEPTION_NAME + " extends Exception {\n"
                +   "   public " + EXCEPTION_NAME + "(String message) {\n"
                +   "       super(message);\n"
                +   "   }\n\n"
                +   "   public " + EXCEPTION_NAME + "(String message, int pos) {\n"
                +   "       System.err.println(String.format(\"ParseException at position %d: %s\", pos, message));\n"
                +   "   }\n"
                +   "}");
        out.close();
    }

    private void generateParser() throws IOException {
        File file = new File(AUTO_GENERATED_PATH, PARSER_NAME + ".java");
        if (!file.createNewFile()) {
            System.err.println("Can't create file " + file.toString());
        }
        PrintWriter out = new PrintWriter(file);
        out.println("import java.io.*;\nimport java.util.*;\n");
        out.println(header + "\n");
        out.println("public class " + PARSER_NAME + "{");
        out.println(members);
        out.println(String.format("    private LexicalAnalyzer analyzer;\n\n"
                +   "    public %s parse(InputStream is) throws ParseException {\n"
                +   "        analyzer = new LexicalAnalyzer(is);\n"
                +   "        analyzer.nextToken();\n"
                +   "        return " + start.name.toLowerCase() + "();\n"
                +   "    }\n", start.getReturnType()));

        HashMap<String, NonTermNode> toAdd = new HashMap<>();
        for (String nonTermNodeName : nonTerminals.keySet()) {
            NonTermNode nonTermNode = nonTerminals.get(nonTermNodeName);
            out.println("    private " + start.getReturnType() +  " " + nonTermNode.name.toLowerCase() +"() throws ParseException {\n"
                        + "        HashMap<String, Object> results = new HashMap<>();\n"
                        + "        switch (analyzer.getCurToken()) {\n");
            for (String termNodeName : terminals.keySet()) {
                TermNode termNode = terminals.get(termNodeName);
                if (termNode.name.equals(EPS_NODE_NAME)) {
                    continue;
                }
                out.print("            case " + termNodeName.toUpperCase() + ":\n");
                Derivation targetProduction = predictionTable.get(new Pair<>(nonTermNode, termNode));
                if (targetProduction == null) {
                    continue;
                }
                for (Node curNode : targetProduction.getNodes()) {
                    if (!curNode.isTerminal) {
                        out.print("                results.put(\"" + curNode.name.toLowerCase() + "\", " + curNode.name.toLowerCase() + "());\n");
                    } else {
                        if (curNode.name.equals(EPS_NODE_NAME)) {
                            continue;
                        }
                        out.print("                if (analyzer.getCurToken() != Token." + curNode.name.toUpperCase() + ") {\n"
                                + "                    throw new ParseException(\") expected at position \" + analyzer.getCurPos(), analyzer.getCurPos());\n"
                                + "                }\n"
                                + "                analyzer.nextToken();\n");
                    }
                }
                String translatingSymbol = targetProduction.getSymbol();
                if (translatingSymbol != null) {
                    out.print("               ");
                    System.out.println(translatingSymbol);
                    int startI = 0;
                    if (translatingSymbol.trim().startsWith("$")) {
                        int ignored = findMemberEnd(translatingSymbol, ++startI);
                        String[] item = parseMember(translatingSymbol, startI);
                        String varName = item[0].substring(1);
                        int endIndex = translatingSymbol.indexOf(';') + 1;
                        String rightExpr = translatingSymbol.substring(translatingSymbol.indexOf('=') + 1, endIndex - 1);
                        startI = endIndex;
                        int replaceIndex = 0;
                        StringBuilder newRightExpr = new StringBuilder();
                        while (replaceIndex < rightExpr.length()) {
                            if (rightExpr.charAt(replaceIndex) != '$') {
                                newRightExpr.append(rightExpr.charAt(replaceIndex++));
                            } else {
                                int nextI = findMemberEnd(rightExpr, ++replaceIndex);
                                String[] items = parseMember(rightExpr, replaceIndex);
                                String name = items[0];
                                newRightExpr.append("(").append(getNonTerminalNode(name).getReturnType()).append(") results.get(\"").
                                        append(name).append("\")");
                                replaceIndex = nextI;
                            }
                        }
                        out.println(" results.put(\"" + varName + "\"," + newRightExpr.toString() + ");");
                    }
                    for (int i = startI; i < translatingSymbol.length();) {
                        if (translatingSymbol.charAt(i) != '$') {
                            out.print(translatingSymbol.charAt(i++));
                        } else {
                            int nextI = findMemberEnd(translatingSymbol, ++i);
                            String[] item = parseMember(translatingSymbol, i);
                            i = nextI;
                            out.print("(" + getNonTerminalNode(item[0]).getReturnType() + ") results.get(\"" + item[0] + "\")");
                        }
                    }
                } else {
                    out.println("            return " + (!NonTermNode.VOID_RETURN_TYPE.equals(nonTermNode.getReturnType()) ? null : "") + ";");
                }
                out.println();
            }

            out.println("            default:\n"
                    +   "                throw new ParseException(\"Incorrect token at " + nonTermNode.name.toLowerCase() + "(): \" + analyzer.getCurToken());\n"
                    +   "        }\n"
                    +   "    }");
        }
        out.println("}");
        out.close();
    }

    private int findMemberEnd(String s, int pos) {
        int pointIndex = s.indexOf('.', pos);
        int spaceIndex = pointIndex + 2;
        while (Character.isLetter(s.charAt(spaceIndex))) {
            spaceIndex++;
        }
        return spaceIndex;
    }

    private String[] parseMember(String s, int pos) {
        int pointIndex = s.indexOf('.', pos);
        int spaceIndex = findMemberEnd(s, pos);
        return new String[] {s.substring(pos, pointIndex), s.substring(pointIndex + 1, spaceIndex)};
    }

    private void generateTokenFile() throws IOException {
        File file = new File(AUTO_GENERATED_PATH, TOKEN_FILE_NAME + ".java");
        if (!file.createNewFile()) {
            System.err.println("Can't create file " + file.toString());
        }
        PrintWriter out = new PrintWriter(file);

        out.print("public enum " + TOKEN_FILE_NAME + " {\n    ");
        List<String> tokenNames = new ArrayList<>(terminals.keySet());

        out.println(String.join(", ", tokenNames.stream().map(String::toUpperCase).collect(Collectors.toList())));
        out.println("}");
        out.close();
    }

    private void generateLexer() throws IOException {
        File file = new File(AUTO_GENERATED_PATH, LEXER_NAME + ".java");
        if (!file.createNewFile()) {
            System.err.println("Can't create file " + file.toString());
        }
        PrintWriter out = new PrintWriter(file);
        out.println("import java.io.*;\n");
        out.println("public class " + LEXER_NAME + "{");
        out.println("    private InputStream is;\n"
                +   "    private int curChar;\n"
                +   "    private int curPos;\n"
                +   "    private Token curToken;\n\n"
                +   "    public LexicalAnalyzer(InputStream is) throws ParseException {\n"
                +   "        this.is = is;\n"
                +   "        curPos = 0;\n"
                +   "        nextChar();\n"
                +   "    }\n\n"
                +   "    private boolean isBlank(int c) {\n"
                +   "        return c == -1 || c == ' ' || c == '\\r' || c == '\\n' || c == '\\t';\n"
                +   "    }\n\n"
                +   "    private void nextChar() throws ParseException {\n"
                +   "        curPos++;\n"
                +   "        try {\n"
                +   "            curChar = is.read();\n"
                +   "        } catch (IOException e) {\n"
                +   "            throw new ParseException(e.getMessage(), curPos);\n"
                +   "        }\n"
                +   "    }\n\n"
                +   "    public Token getCurToken() {\n"
                +   "        return curToken;\n"
                +   "    }\n\n"
                +   "    public int getCurPos() {\n"
                +   "        return curPos;\n"
                +   "    }\n\n"
                +   "    public void nextToken() throws ParseException {\n"
                +   "        if (curChar == -1) {\n"
                +   "            curToken = Token.END;\n"
                +   "            return;\n"
                +   "        }\n"
                +   "        while (isBlank(curChar)) {\n"
                +   "            nextChar();\n"
                +   "        }\n"
                +   "        StringBuilder sb = new StringBuilder();\n"
                +   "        sb.append((char) curChar);\n"
                +   "        if (curChar >= 'a' && curChar <= 'z') {\n"
                +   "            nextChar();\n"
                +   "            while (!isBlank(curChar) && curChar != '(' && curChar != ')') {\n"
                +   "                sb.append((char) curChar);\n"
                +   "                nextChar();\n"
                +   "            }\n"
                +   "        } else {\n"
                +   "            nextChar();\n"
                +   "        }\n"
                +   "        String token = sb.toString();\n");
        out.println("        switch (token) {");
        HashSet<String> used = new HashSet<>();
        for (String tokenString : terminals.keySet()) {
            for (String productionString : terminals.get(tokenString).getProductions()) {
                if (!used.contains(productionString)) {
                    out.println(String.format(
                            "            case \"%s\":\n"
                                    + "                curToken = Token.%s;\n"
                                    + "                break;", productionString, tokenString.toUpperCase()));
                }
                used.add(productionString);
            }
        }
        out.println("        }\n"
                +   "    }\n"
                +   "}");
        out.close();

    }

    private void cleanGenerateDirectory() throws IOException {
        File root = new File(AUTO_GENERATED_PATH);
        if (root.isDirectory()) {
            File[] files = root.listFiles();
            if (files == null) {
                return;
            }
            for (File file : files) {
                if (!file.delete()) {
                    System.err.println("Can't deleted file " + file.toString());
                }
            }
        }
    }

    private String removeFirstCharacter(String string) {
        return string.substring(1, string.length() - 1);
    }
}
