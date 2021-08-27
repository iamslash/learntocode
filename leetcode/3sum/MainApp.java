// Copyright (C) 2021 by iamslash

import java.util.*;

// nums: -1 0 1 2 -1 -4
//           i
//       -4 -1 -1 0 1 2
//              j
//                    k

// 483ms 16.90% 43MB 57.76%
// hash set, sort
// O(N^2) O(N)
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if (nums.length < 3) {
            return new ArrayList<>();
        }
        Set<List<Integer>> ans = new HashSet<>();
        Arrays.sort(nums);
        int n = nums.length;
        for (int i = 0; i < n-2; ++i) {
            int j = i+1, k = n-1;
            while (j < k) {
                if ((nums[i] < 0 && nums[k] < 0) ||
                    (nums[i] > 0 && nums[k] > 0)) {
                    break;
                }
                if (nums[i] + nums[j] + nums[k] < 0) {
                    ++j;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    --k;
                } else {
                    ans.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    ++j;
                    --k;
                }
            }
        }
        return new ArrayList<>(ans);
    }
}

public class MainApp {
  public static void main(String[] args) {
      Set<List<Integer>> sss = new HashSet<>();
      sss.add(Arrays.asList(1, 2, 3));
      sss.add(Arrays.asList(1, 2, 3));
      System.out.println(sss.size());
      List<List<Integer>> lll = new ArrayList<>(sss);
  }
}
