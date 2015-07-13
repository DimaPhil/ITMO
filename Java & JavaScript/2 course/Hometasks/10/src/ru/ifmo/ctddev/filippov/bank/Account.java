package ru.ifmo.ctddev.filippov.bank;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Account extends Remote {
    public long getBalance() throws RemoteException;
    public void setBalance(long balance) throws RemoteException;
    public long increaseBalance(long delta) throws RemoteException;
    public long decreaseBalance(long delta) throws RemoteException;
    public String getId() throws RemoteException;
}
