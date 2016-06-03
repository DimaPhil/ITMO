package ru.ctddev.filippov.pg;

class Node {
    protected String name;
    protected boolean isTerminal;

    Node(String name) {
        this.name = name;
    }

    @Override
    public boolean equals(Object o) {
        return (getClass() == o.getClass() && name.equals(((Node) o).name));
    }

    boolean isTerminal() {
        return isTerminal;
    }
}
