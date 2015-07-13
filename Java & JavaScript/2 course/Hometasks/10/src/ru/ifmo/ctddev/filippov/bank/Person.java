package ru.ifmo.ctddev.filippov.bank;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Person extends Remote {
    String getName() throws RemoteException;
    String getSurname() throws RemoteException;
    String getId() throws RemoteException;
    PersonType getType() throws RemoteException;
}