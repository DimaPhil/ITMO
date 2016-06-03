package ru.ctddev.filippov.pg;

import java.util.ArrayList;
import java.util.List;

class Derivation {
    private List<Node> nodes = new ArrayList<>();
    private String symbol;

    void addNode(Node node) {
        nodes.add(node);
    }

    int size() {
        return nodes.size();
    }

    Node getNode(int pos) {
        return nodes.get(pos);
    }

    List<Node> getNodes() {
        return nodes;
    }

    void setSymbol(String symbol) {
        this.symbol = symbol;
    }

    String getSymbol() {
        return symbol;
    }
}
