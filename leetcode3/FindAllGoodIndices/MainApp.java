// Copyright (C) 2022 by iamslash

import java.util.*;

//    k: 2
//                   i
//   nums:   2 1 1 1 3 4 1
//  lefts: 1 1 2 3 4 1 1 2
// rights: 1 1 5 4 3 2 1 1

// Idea: iterative dynamic programming
//
// leftBig[] is the count of left big nums
// rightBig[] is the count of right big nums
// find index i which leftBig[i] >= k && rightBig[k] >= k

// 16ms 70.61% 110.8MB 81.38%
// iterative dynamic programming
// O(N) O(N)
class Solution {
    public List<Integer> goodIndices(int[] nums, int k) {
        int n = nums.length;
        int[] leftBig = new int[n+1];
        int[] rightBig = new int[n+1];
        Arrays.fill(leftBig, 1);
        Arrays.fill(rightBig, 1);
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i < n; ++i) {
            if (nums[i-1] >= nums[i]) {
                leftBig[i] = leftBig[i-1] + 1;
            }
        }
        for (int i = n-2; i >= 0; --i) {
            if (nums[i] <= nums[i+1]) {
                rightBig[i] = rightBig[i+1] + 1;
            }
        }
        for (int i = k; i < n - k; ++i) {
            if (leftBig[i-1] >= k && rightBig[i+1] >= k) {
                ans.add(i);
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
