// Copyright (C) 2022 by iamslash

import java.util.*;

// 10ms 7.69% 62.4MB 21.54%
// partial sum
// O(N) O(N)
class Solution {
    public long maximumSumScore(int[] nums) {
        int n = nums.length;
        long sum = 0, maxScore = Integer.MIN_VALUE;
        long[] ps = new long[n+1];
        for (int i = 0; i < n; ++i) {
            ps[i+1] = ps[i] + nums[i];
            sum += nums[i];
        }
        for (int i = 0; i < n; ++i) {
            long lSum = ps[i+1];
            long rSum = sum - ps[i];
            // System.out.printf("lSum: %d, rSum: %d\n", lSum, rSum);
            maxScore = Math.max(maxScore, Math.max(lSum, rSum));
        }
        return maxScore;
    }
}

// Why this is an answer???
// Is it not sum - ps but sum - ps + nums[i] ???
// 1ms 100.00% 59.2MB 89.23%
// partial sum
// O(N) O(1)
class Solution {
    public long maximumSumScore(int[] nums) {
        int n = nums.length;
        long sum = 0;
        for (int a : nums) {
            sum += a;
        }
        long maxScore = sum, ps = 0;
        for (int i = 0; i < n-1; ++i) {
            ps += nums[i];
            long score = Math.max(ps, sum - ps);
            maxScore = Math.max(maxScore, score);
        }
        return maxScore;
    }
}

// 3ms 63.08% 62MB 26.15%
// partial sum
// O(N) O(1)
class Solution {
    public long maximumSumScore(int[] nums) {
        int n = nums.length;
        long sum = 0;
        for (int a : nums) {
            sum += a;
        }
        long maxScore = sum, ps = 0;
        for (int i = 0; i < n; ++i) {
            ps += nums[i];
            long score = Math.max(ps, sum - ps + nums[i]);
            // System.out.printf("lSum: %d, rSum: %d\n", ps, sum-ps+nums[i]);
            maxScore = Math.max(maxScore, score);
        }
        return maxScore;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
