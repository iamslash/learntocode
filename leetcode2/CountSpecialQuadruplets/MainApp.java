// Copyright (C) 2021 by iamslash

import java.util.*;

// i   
// 1 2 3 6
// j
//       k
// 

// 7ms 98.56% 38.4MB 71.05%
// hash map
// O(N^2) O(N^2)
class Solution {
    public int countQuadruplets(int[] nums) {
        int ans = 0;
        int n = nums.length;
        Map<Integer, Integer> cntMap = new HashMap<>();
        cntMap.put(nums[n-1] - nums[n-2], 1);
        for (int i = n-3; i >= 1; --i) {
            for (int j = i-1; j >= 0; --j) {
                ans += cntMap.getOrDefault(nums[i] + nums[j], 0);
            }
            for (int k = n-1; k > i; --k) {
                cntMap.put(nums[k] - nums[i],
                           cntMap.getOrDefault(nums[k] - nums[i], 0) + 1);
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
