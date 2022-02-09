// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 1 2 3 4 5
//       1 2
//         2 3
//           3 4
//             4 5
//       1   3
//         2   4
//           3   5
//       1     4
//         2     5
//       1       5

// Wrong Answer
//   Your input: [4,1,2,3]
//       Output: -
//     Expected: 13
// sort
// O(NlgN) O(1)
class Solution {
    public long subArrayRanges(int[] nums) {
        Arrays.sort(nums);
        int sum = 0, n = nums.length;
        for (int i = 1; i < n; ++i) {
            sum += nums[i] - nums[i-1];
        }
        return sum * (n-1);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
