// Copyright (C) 2022 by iamslash

import java.util.*;

//  deposit: 0 0 1 2 1   0 0 1 2 1 
// withdraw: 600         0 0 0 2 0
//  deposit: 0 1 0 1 1   0 1 0 3 1
// withdraw: 600         
// withdraw: 500         0 0 0 3 0

//  deposit: 0 10 0 3 0  0 10 0 3 0
// withdraw: 500         0  2 0 2 0

// Idea:
// Data type is important.

// 137ms 83.89% 50.6MB 73.79%
// hash map
//  deposit: O(1) O(1)
// withdraw: O(1) O(1)
class ATM {
    int[] banknotes = new int[]{20, 50, 100, 200, 500};
    long[] caps = new long[5];
    public void deposit(int[] deltas) {
        for (int i = 0; i < 5; ++i) {
            caps[i] += deltas[i];
        }
    }    
    public int[] withdraw(int amount) {
        int[] deltas = new int[5];
        for (int i = 4; i >= 0 && amount > 0; --i) {
            long used = Math.min(caps[i], amount / banknotes[i]);
            amount -= used * banknotes[i];
            deltas[i] = (int)used;
        }
        if (amount > 0) {
            return new int[]{-1};
        }
        for (int i = 0; i < 5; ++i) {
            caps[i] -= deltas[i];
        }
        return deltas;
    }
}
