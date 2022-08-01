// Copyright (C) 2022 by iamslash

import java.util.*;

// 0ms 100.00% 69.9MB 67.26%
// right most equal binary search 
// O(lgN) O(1)
class Solution {
    public int maximumGroups(int[] grades) {
        long lo = 1, hi = 100_000, mi = 0, n = grades.length;
        while (lo < hi) {
            mi = (lo + hi + 1) / 2;
            long sum = mi * (mi + 1) / 2;
            if (sum <= n) {
                lo = mi;
            } else {
                hi = mi - 1;
            }
        }
        return (int)lo;
    }
}

// Idea: math
//
// 1 + 2 + ... + k <= n
// k(k + 1) / 2 <= n
// (k + 0.5)(k + 0.5) <= n * 2 + 0.25
// k + 0.5 <= sqrt(n * 2 + 0.25)
// k <= sqrt(n * 2 + 0.25) - 0.5

// 0ms 100.00% 69.5MB 81.19%
// math
// O(1) O(1)
class Solution {
    public int maximumGroups(int[] grades) {
        return (int)(Math.sqrt(grades.length * 2 + 0.25) - 0.5);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
