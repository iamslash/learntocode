// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 0 1 2
//       1 2
//       2
//       .
//       0
//       0 1

// nums: 0 1
//       1
//       .
//       0

// 11ms 23.36% 167MB 16.79%
// brute force
// O(N) O(1)
class Solution {
    private int getNum(int[] nums, int time, int pos) {
        int n = nums.length;
        time %= (n * 2);
        if (time <= n) {
            if (time+pos < n) {
                return nums[time+pos];
            }
        } else {
            if (pos < time-n) {
                return nums[pos];
            }
        }
        return -1;
    }
    public int[] elementInNums(int[] nums, int[][] queries) {
        int n = queries.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int[] query = queries[i];
            ans[i] = getNum(nums, query[0], query[1]);
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
