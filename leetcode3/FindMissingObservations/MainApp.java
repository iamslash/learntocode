// Copyright (C) 2022 by iamslash

import java.util.*;

// (12 + nSum) / (4 + 2) = 4
// nSum = 24 - 12 = 12

//    m: 3
//    n: 4
// mSum: 12
// nSum: 21 - 12 = 9

// mean: 4
//    m: 4
//    n: 2
// mSum: 11
// nSum: 24 - 11 = 13

// math
// O(M) O(N)
class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int m = rolls.length;
        int mSum = 0;
        for (int roll : rolls) {
            mSum += roll;
        }
        int nSum = (m + n) * 4 - mSum;
        int quo = nSum / n;
        int rem = nSum % n;
        if ((quo == 6 && rem > 0) ||
            quo > 6) {
            return new int[0];
        }
        int[] missings = new int[n];
        Arrays.fill(missings, quo);
        if (rem > 0) {
            missings[n-1] = rem;
        }
        return missings;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
