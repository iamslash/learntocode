// Copyright (C) 2022 by iamslash

import java.util.*;

// n: 12

// 0ms 100.00% 41.7MB 5.50%
// brute foce
// O(N!) O(N)
class Solution {
    private int[] countEvenOdd(int n) {
        // [event digits, odd digits]
        int[] ans = new int[2];
        while (n > 0) {
            ans[n % 10 % 2]++;
            n /= 10;
        }
        return ans;
    }
    public int closestFair(int n) {
        int[] cnts = countEvenOdd(n);
        // base
        if ((cnts[0] + cnts[1]) % 2 == 1) {
            if (n < 10) {
                return 10;
            }
            if (n < 1001) {
                return 1001;
            }
            if (n < 100011) {
                return 100011;
            }
            if (n < 10000111) {
                return 10000111;
            }
            return 1000001111;
        }
        // recursion
        while (cnts[0] != cnts[1]) {
            cnts = countEvenOdd(++n);
            if ((cnts[0] + cnts[1]) % 2 == 1) {
                return closestFair(n);
            }
        }
        return n;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
