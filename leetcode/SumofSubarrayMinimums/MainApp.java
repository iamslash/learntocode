// Copyright (C) 2022 by iamslash

import java.util.*;


// i
// 3 1 2 4
// 

// 975ms 5.02% 62.2MB 55.50%
// math
// O(N) O(1)
class Solution {
    public int sumSubarrayMins(int[] A) {
        int MOD = 1_000_000_007;
        long sum = 0;
        int n = A.length, l, r;
        for (int i = 0; i < n; ++i) {
            l = i - 1; r = i + 1;
            while (l >= 0 && A[l] > A[i]) {
                --l;
            }
            while (r < n && A[r] >= A[i]) {
                ++r;
            }
            sum += (long)A[i] * (i-l) * (r-i);
            sum %= MOD;
        }
        return (int)sum;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
