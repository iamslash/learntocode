// Copyright (C) 2022 by iamslash

import java.util.*;

//         i
//   nums: 2 4 6 4
//  lefts: 0 1 2 2
// rights: 0 3 3 3

//         i
//   nums: 1 2 3
//  lefts: 0 1 0
// rights: 0 1 0

// 10ms 53.01% 97.4MB 35.24%
// hash map
// O(N) O(N)
class Solution {
    public int sumOfBeauties(int[] nums) {
        int n = nums.length, ans = 0;
        int[] lefts = new int[n];
        int[] rights = new int[n];
        rights[n-1] = n-1;
        for (int i = 1; i < n-1; ++i) {
            lefts[i] = nums[lefts[i-1]] < nums[i] ? i : lefts[i-1];
        }
        for (int i = n-2; i > 0; --i) {
            rights[i] =  nums[i] < nums[rights[i+1]] ? i : rights[i+1];
        }
        // dump(lefts);
        // dump(rights);
        for (int i = 1; i < n-1; ++i) {
            if (lefts[i] == rights[i]) {
                ans += 2;
            } else if (nums[i-1] < nums[i] && nums[i] < nums[i+1]) {
                ans += 1;
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
