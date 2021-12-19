package test.work.demo.entity;

import java.io.Serializable;
import java.sql.Timestamp;

/**
 * @author 何庆晟
 */

public class Account implements Serializable {
    public static long serialVersionUID = 1L;

    private int id;
    private String accout;
    private String password;
    private double balance;
    private Timestamp started;
    private Timestamp updated;

    public Account(String accout, String password, double balance, Timestamp started, Timestamp updated) {
        this.accout = accout;
        this.password = password;
        this.balance = balance;
        this.started = started;
        this.updated = updated;
    }

    public Account() {
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getAccout() {
        return accout;
    }

    public void setAccout(String accout) {
        this.accout = accout;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public Timestamp getStarted() {
        return started;
    }

    public void setStarted(Timestamp started) {
        this.started = started;
    }

    public Timestamp getUpdated() {
        return updated;
    }

    public void setUpdated(Timestamp updated) {
        this.updated = updated;
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        return super.equals(obj);
    }

    @Override
    public String toString() {
        return super.toString();
    }
}
