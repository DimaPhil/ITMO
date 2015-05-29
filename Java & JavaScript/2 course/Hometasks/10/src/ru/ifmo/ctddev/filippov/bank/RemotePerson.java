package ru.ifmo.ctddev.filippov.bank;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class RemotePerson extends UnicastRemoteObject implements Person {
    private final LocalPerson person;

    public RemotePerson(String name, String surname, String id) throws RemoteException {
        super();
        this.person = new LocalPerson(name, surname, id);
    }

    @Override
    public String getName() throws RemoteException {
        return person.getName();
    }

    @Override
    public String getSurname() throws RemoteException {
        return person.getSurname();
    }

    @Override
    public String getId() throws RemoteException {
        return person.getId();
    }

    @Override
    public PersonType getType() throws RemoteException {
        return PersonType.REMOTE;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (!(o instanceof RemotePerson)) {
            return false;
        }

        RemotePerson rhs = (RemotePerson) o;
        if (person != null ? !person.equals(rhs.person) : rhs.person != null) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int result = 1;
        result = result * 239017 + (person != null ? person.hashCode() : 0);
        return result;
    }
}