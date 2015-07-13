package ru.ifmo.ctddev.filippov.bank;

import static ru.ifmo.ctddev.filippov.bank.Utils.*;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.concurrent.ConcurrentHashMap;
import java.util.stream.Collectors;

public class BankImpl extends UnicastRemoteObject implements Bank {
    ConcurrentHashMap<Person, HashMap<String, Account>> database = new ConcurrentHashMap<>();

    public BankImpl() throws RemoteException { super(); }

    private Person getLocalPerson(Person person) throws RemoteException {
        if (person.getType() == PersonType.REMOTE) {
            return new RemotePerson(person.getName(), person.getSurname(), person.getId());
        }
        return person;
    }

    private boolean containsPair(Person person, String accountId) throws RemoteException {
        return database.containsKey(getLocalPerson(person)) && database.get(getLocalPerson(person)).containsKey(accountId);
    }

    @Override
    public void addAccount(Person person, String accountId) throws RemoteException {
        Person newPerson;
        if (person.getType() == PersonType.LOCAL) {
            newPerson = new LocalPerson(person.getName(), person.getSurname(), person.getId());
        } else {
            newPerson = new RemotePerson(person.getName(), person.getSurname(), person.getId());
        }
        database.putIfAbsent(newPerson, new HashMap<>());
        database.get(newPerson).putIfAbsent(accountId, new AccountImpl(accountId));
    }

    @Override
    public List<Person> searchPersonByName(String name, String surname, PersonType type) throws RemoteException {
        return database.keySet().stream().parallel().filter(ignored(p -> p.getName().equals(name) &&
                p.getSurname().equals(surname) &&
                p.getType() == type)).collect(Collectors.toList());
    }

    @Override
    public List<Person> searchPersonById(String id) {
        return database.keySet().stream().parallel().filter(ignored(p -> p.getId().equals(id))).collect(Collectors.toList());
    }

    @Override
    public List<Account> getAccounts(Person person) throws RemoteException {
        if (!database.keySet().contains(getLocalPerson(person))) {
            return null;
        }
        return new ArrayList<>(database.get(getLocalPerson(person)).values());
    }

    @Override
    public Long getBalance(Person person, String accountId) throws RemoteException {
        if (!containsPair(getLocalPerson(person), accountId)) {
            return null;
        }
        return database.get(getLocalPerson(person)).get(accountId).getBalance();
    }
}