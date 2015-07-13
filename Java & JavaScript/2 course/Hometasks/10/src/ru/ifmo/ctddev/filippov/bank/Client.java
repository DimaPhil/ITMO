package ru.ifmo.ctddev.filippov.bank;

import static ru.ifmo.ctddev.filippov.bank.Utils.*;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NoSuchObjectException;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.Arrays;
import java.util.List;
import java.util.Optional;
import java.util.function.Consumer;

@SuppressWarnings("ConstantConditions")
public class Client {
    private static final String USAGE = "Usage: name surname id accountId [+|-]money";

    private static void printCurrentState(Bank bank, Person person, String accountId) throws RemoteException {
        System.out.println("Current balance: " + bank.getBalance(person, accountId));
        System.out.println();
        System.out.println(person.getName() + " " + person.getSurname());
        System.out.println("Your current account list: \nID,   Balance");
        bank.getAccounts(person).forEach(account -> {
            String balance = "Can't display balance";
            String id = "???";
            try {
                balance = String.valueOf(account.getBalance());
                id = account.getId();
            } catch (RemoteException e) {

            }
            System.out.println(id + "   " + balance);
        });
        System.out.println();
    }

    public static void main(String[] args) {
        if (args == null ||
                args.length != 5 ||
                Arrays.stream(args).anyMatch(a -> a == null) ||
                Arrays.stream(args).anyMatch(a -> a.length() == 0) ||
                args[4].length() < 2) {
            System.err.println(USAGE);
            return;
        }
        String name = args[0];
        String surname = args[1];
        String id = args[2];
        String accountId = args[3];

        char deltaChar;
        long delta;
        try {
            deltaChar = args[4].charAt(0);
            if (deltaChar != '+' && deltaChar != '-') {
                throw new NumberFormatException();
            }
            delta = Long.parseLong(args[4].substring(1, args[4].length()));
        } catch (NumberFormatException e) {
            System.out.println("Wrong money description");
            System.err.println(USAGE);
            return;
        }
        try {
            PersonType currentType = PersonType.REMOTE;

            Bank bank = (Bank) Naming.lookup("rmi://localhost:1234/bank");
            Person person;
            if (currentType == PersonType.REMOTE) {
                person = new RemotePerson(name, surname, id);
            } else {
                person = new LocalPerson(name, surname, id);
            }

            Consumer<Void> executor = (anything) -> {
                try {
                    if (currentType == PersonType.REMOTE && !UnicastRemoteObject.unexportObject(person, false)) {
                        System.err.println("Failed to unexport person");
                    }
                } catch (NoSuchObjectException e) {
                    System.out.println(e.toString());
                }
                System.exit(0);
            };

            //List<Person> personList = bank.searchPersonByName(name, surname, currentType);
            List<Person> personList = bank.searchPersonById(id);
            if (personList.isEmpty()) {
                bank.addAccount(person, accountId);
                System.out.println("Created new account with id " + accountId + " with balance 0");
                executor.accept(null);
            }
            //if (personList.stream().noneMatch(ignored(p -> p.getId().equals(person.getId())))) {
            if (!personList.get(0).getName().equals(person.getName()) || !personList.get(0).getSurname().equals(person.getSurname())) {
                //System.out.println("Your id doesn't match, sorry");
                System.out.println("Duplicate id with other name, sorry");
                executor.accept(null);
            }
            List<Account> accounts = bank.getAccounts(person);
            Optional<Account> current = accounts.stream().filter(ignored(p -> p.getId().equals(accountId))).findFirst();
            if (!current.isPresent()) {
                bank.addAccount(person, accountId);
                System.out.println("Created new account with id " + accountId + " with balance 0");
                executor.accept(null);
            }
            Account account = current.get();
            Long balance = account.getBalance();
            System.out.println("Balance on account " + accountId + " before update: " + balance);
            if (deltaChar == '+') {
                account.increaseBalance(delta);
            } else {
                account.decreaseBalance(delta);
            }
            printCurrentState(bank, person, accountId);
            executor.accept(null);
        } catch (RemoteException | MalformedURLException | NotBoundException e) {
            System.out.println(e.toString());
        }
    }
}