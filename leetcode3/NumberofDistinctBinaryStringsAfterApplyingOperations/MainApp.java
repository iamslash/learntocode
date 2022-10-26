// Copyright (C) 2022 by iamslash

import java.util.*;

// s: 1 0 0 1
// k: 3

// 9ms 100.00% 46.5MB 100.00%
// math
// O(N) O(1)
class Solution {
    public int countDistinctStrings(String s, int k) {
        int n = s.length(), ans = 1;
        int MOD = 1_000_000_007;
        for (int i = 0; i <= n - k; ++i) {
            ans = (ans * 2) % MOD;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
