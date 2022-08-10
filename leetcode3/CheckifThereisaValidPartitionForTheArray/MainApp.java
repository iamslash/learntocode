// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea: iterative dynamic programming
//
// Define C[] for cache.
// C[i % 4]: partionable for A[0..i]?
// 4 is enough for previous elements to check.
// C[3] is true for seed value.
// (i + 2) % 4 means positive 2 previous index from i. 
// (i + 1) % 4 means positive 3 previous index from i.
//
// Check all partitionable cases. 
// Check s[i-1], s[i] are exactly 2 equal elements then
//   C[i] |= C[i-2]
// Check s[i-2], s[i-1], s[i] are exactly 3 equal elements then
//   C[i] |= C[i-3]
// Check s[i-2], s[i-1], s[i] are exactly 3 consecutive increasing elements then
//   C[i] |= C[i-3]
// Finally the answer is C[(n - 1) % 4].

//    C: f f f t
// nums: 4 4 4 5 6
//         i

// 13ms 9.09%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public boolean validPartition(int[] nums) {
        int n = nums.length;
        boolean[] C = new boolean[4];
        C[3] = true;  // seed value
        for (int i = 0; i < n; ++i) {
            C[i % 4] = false;
            if (i >= 1 && nums[i - 1] == nums[i]) {
                C[i % 4] |= C[(i + 2) % 4];
            }
            if (i >= 2 && nums[i - 2] == nums[i - 1] &&
                nums[i - 1] == nums[i]) {
                C[i % 4] |= C[(i + 1) % 4];
            }
            if (i >= 2 && nums[i - 2] + 1 == nums[i - 1] &&
                nums[i - 1] + 1 == nums[i]) {
                C[i % 4] |= C[(i + 1) % 4];
            }
        }
        return C[(n-1) % 4];
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
