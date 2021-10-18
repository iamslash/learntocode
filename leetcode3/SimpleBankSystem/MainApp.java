// Copyright (C) 2021 by iamslash

import java.util.*;

// 155ms 60.49% 154.5MB 75.20%
// brute force
// transfer: O(1) O(N)
//  deposit: O(1) O(N)
// withdraw: O(1) O(N)
class Bank {
    private long[] balance;

    public Bank(long[] balance) {
        this.balance = balance;
    }
    
    public boolean transfer(int acc1, int acc2, long money) {
        if (acc1 > balance.length || acc2 > balance.length) {
            return false;
        }
        if (balance[acc1-1] < money) {
            return false;
        }
        balance[acc1-1] -= money;
        balance[acc2-1] += money;
        return true;
    }
    
    public boolean deposit(int acc, long money) {
        if (acc > balance.length) {
            return false;
        }
        balance[acc-1] += money;
        return true;
    }
    
    public boolean withdraw(int acc, long money) {
        if (acc > balance.length) {
            return false;
        }
        if (balance[acc-1] < money) {
            return false;
        }
        balance[acc-1] -= money;
        return true;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
