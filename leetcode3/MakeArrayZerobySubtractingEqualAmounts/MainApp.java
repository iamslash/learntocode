// Copyright (C) 2022 by iamslash

import java.util.*;

// 0ms 100.00% 42.1MB 34.03%
// hash map
// O(N) O(1)
class Solution {
    public int minimumOperations(int[] nums) {
        boolean[] exists = new boolean[101];
        for (int a : nums) {
            exists[a] = true;
        }
        int ans = 0;
        for (int a = 1; a <= 100; ++a) {
            ans += exists[a] ? 1 : 0;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
