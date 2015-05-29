package ru.ifmo.ctddev.filippov.bank;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.concurrent.atomic.AtomicLong;

public class AccountImpl extends UnicastRemoteObject implements Account {
    private AtomicLong balance;
    private final String accountId;

    public AccountImpl(String accountId) throws RemoteException {
        super();
        this.accountId = accountId;
        balance = new AtomicLong(0);
    }

    public long getBalance() {
        return balance.longValue();
    }

    public void setBalance(long newAmount) {
        balance.set(newAmount);
    }

    public long increaseBalance(long delta) {
        return balance.addAndGet(delta);
    }

    public long decreaseBalance(long delta) {
        return balance.updateAndGet(s -> s - delta);
    }

    @Override
    public String getId() throws RemoteException {
        return accountId;
    }
}