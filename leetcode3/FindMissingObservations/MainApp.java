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


// Wrong Answer for
// [1,5,6]
// 3
// 4

// mean: 3
//    m: 3
//    n: 2
// mSum: 12
// nSum: 3

// 3ms 96.52% 60.6MB 88.56%
// math
// O(M) O(N)
class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int m = rolls.length;
        int mSum = 0;
        for (int roll : rolls) {
            mSum += roll;
        }
        int nSum = (m + n) * mean - mSum;
        if (nSum < n || nSum > 6 * n) {
            return new int[0];
        }
        int quo = nSum / n;
        int rem = nSum % n;
        int[] missings = new int[n];
        Arrays.fill(missings, quo);
        for (int i = 0; i < rem; ++i) {
            missings[i]++;
        }
        return missings;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
