package ru.ifmo.ctddev.filippov.bank;

import java.io.Serializable;
import java.rmi.RemoteException;

public class LocalPerson implements Person, Serializable {
    private static final long serialVersionUID = 7682320920129040221L;
    private final String name, surname, id;

    public LocalPerson(String name, String surname, String id) throws RemoteException {
        super();
        this.name = name;
        this.surname = surname;
        this.id = id;
    }

    @Override
    public String getName() throws RemoteException {
        return name;
    }

    @Override
    public String getSurname() throws RemoteException {
        return surname;
    }

    @Override
    public String getId() throws RemoteException {
        return id;
    }

    @Override
    public PersonType getType() throws RemoteException {
        return PersonType.LOCAL;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (!(o instanceof LocalPerson)) {
            return false;
        }

        LocalPerson rhs = (LocalPerson) o;

        if (id != null ? !id.equals(rhs.id) : rhs.id != null) {
            return false;
        }
        if (name != null ? !name.equals(rhs.name) : rhs.name != null) {
            return false;
        }
        if (surname != null ? !surname.equals(rhs.surname) : rhs.surname != null) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int result = name != null ? name.hashCode() : 0;
        result = result * 239017 + (surname != null ? surname.hashCode() : 0);
        result = result * 239017 + (id != null ? id.hashCode() : 0);
        return result;
    }

    @Override
    public String toString() {
        return "LocalPerson(" +
                "name = \"" + name + "\"" +
                ", surname = \"" + surname + "\"" +
                ", id = \"" + id + "\"" +
                ')';
    }
}