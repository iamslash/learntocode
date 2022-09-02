// Copyright (C) 2022 by iamslash

import java.util.*;


// initEnergy:   5
//    initExp:   3
//   energies:   1 4 3 2
//       exps:   2 6 3 1
//     sumExp: 3 5 
//   trainExp:                

// Idea: greedy
//
// energies should be strictly greater.
// experiences should be strictly greater.
// We can increment one by one, energy or experiences.
// We don't spend inrement for energy.
// We need to find minimum training hours.

// 1ms 51.33% 42.5MB 27.03%
// greedy
// O(N) O(1)
class Solution {
    public int minNumberOfHours(int initEnergy,
                                int initExp,
                                int[] energies,
                                int[] exps) {
        int n = energies.length;
        int sumEnergy = 0, sumExp = initExp;
        int trainEnergy = 0, trainExp = 0;
        for (int energy : energies) {
            sumEnergy += energy;
        }
        if (sumEnergy - initEnergy >= 0) {
            trainEnergy = sumEnergy - initEnergy + 1;
        }
        for (int exp : exps) {
            // Found problematic exp
            if (sumExp <= exp) {
                trainExp += exp - sumExp + 1;
                sumExp = exp + 1;
            }
            sumExp += exp;
        }
        return trainEnergy + trainExp;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
