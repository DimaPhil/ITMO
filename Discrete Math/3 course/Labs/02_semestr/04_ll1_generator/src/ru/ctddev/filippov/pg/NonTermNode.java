package ru.ctddev.filippov.pg;

import java.util.ArrayList;
import java.util.List;

class NonTermNode extends Node {
    static final String VOID_RETURN_TYPE = "void";
    private List<Derivation> productions = new ArrayList<>();
    private String returnType = VOID_RETURN_TYPE;

    NonTermNode(String name) {
        super(name);
        isTerminal = false;
    }

    void addProductionsList(List<Derivation> productions) {
        this.productions.addAll(productions);
    }

    List<Derivation> getProductions() {
        return productions;
    }

    @Override
    public String toString() {
        return name;
    }

    String getReturnType() {
        return returnType;
    }

    void setReturnType(String returnType) {
        this.returnType = returnType;
    }
}
