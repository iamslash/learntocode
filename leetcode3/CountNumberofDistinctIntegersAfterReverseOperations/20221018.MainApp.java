// Copyright (C) 2022 by iamslash

import java.util.*;

// 178ms 53.19% 124.5MB 66.45%
// math
// O(N) O(1)
class Solution {
    private int reverse(int a) {
        int ans = 0;
        while (a > 0) {
            ans = ans * 10 + a % 10;
            a /= 10;
        }
        return ans;
    }
    public int countDistinctIntegers(int[] nums) {
        Set<Integer> numSet = new HashSet<>();
        for (int num : nums) {
            numSet.add(num);
            numSet.add(reverse(num));
        }
        return numSet.size();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
