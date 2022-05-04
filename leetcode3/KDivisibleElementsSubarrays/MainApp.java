// Copyright (C) 2022 by iamslash

import java.util.*;

//    k: 2
//    p: 2
// nums: 2 3 3 2 2

// 73ms 94.80% 66.8MB 82.17%
// set, rolling hash
// O(N^2) O(N)
class Solution {
    public int countDistinct(int[] nums, int k, int p) {
        int n = nums.length, subarrayCnt = 0;
        Set<Long> subarraySet = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            int divCnt = 0;
            long hash = 1;
            for (int j = i; j < n; ++j) {
                hash = hash * 199L + nums[j];
                if (nums[j] % p == 0) {
                    divCnt++;
                }
                if (divCnt <= k) {
                    subarraySet.add(hash);
                }
            }
        }
        return subarraySet.size();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
