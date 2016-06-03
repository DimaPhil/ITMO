package ru.ctddev.filippov.pg;

import java.util.ArrayList;
import java.util.List;

class TermNode extends Node {
    private List<String> productions = new ArrayList<>();

    TermNode(String name) {
        super(name);
        isTerminal = true;
    }

    void addProduction(String production) {
        productions.add(production);
    }

    List<String> getProductions() {
        return productions;
    }
}
