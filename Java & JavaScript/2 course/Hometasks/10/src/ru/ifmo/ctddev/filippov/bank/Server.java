package ru.ifmo.ctddev.filippov.bank;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;

public class Server {
    public static void main(String[] args) {
        try {
            LocateRegistry.createRegistry(1234);
            Bank bank = new BankImpl();
            Naming.rebind("//localhost:1234/bank", bank);
            System.out.println("Successfully started bank server");
        } catch (RemoteException | MalformedURLException e) {
            System.err.println("Couldn't start the bank server");
            System.out.println(e.toString());
        }
    }
}
