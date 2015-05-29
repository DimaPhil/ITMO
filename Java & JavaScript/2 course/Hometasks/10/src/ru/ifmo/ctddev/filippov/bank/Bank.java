package ru.ifmo.ctddev.filippov.bank;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;

public interface Bank extends Remote {
    public void addAccount(Person person, String accountId) throws RemoteException;
    public List<Person> searchPersonByName(String name, String surname, PersonType type) throws RemoteException;
    public List<Person> searchPersonById(String id) throws RemoteException;
    public List<Account> getAccounts(Person person) throws RemoteException;
    public Long getBalance(Person person, String accountId) throws RemoteException;
}