// Copyright (C) 2022 by iamslash

import java.util.*;

//    k: 2
//             i
// nums: 1 2 3 5 6
//                 j
//  cnt: 2

// 46ms 57.14% 78.9MB 28.57%
// sort, two pointers
// O(NlgN) O(1)
class Solution {
    public int partitionArray(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length, cnt = 1, i = 0, j = 0;
        while (j < n) {
            while (j < n && nums[j] - nums[i] <= k) {
                j++;
            }
            if (j < n) {
                cnt++;
                i = j;
            }
        }
        return cnt;
    }
}


//    k: 2
// nums: 1 2 3 5 6
//       

// 28ms 85.71% 90.2MB 28.57
// hash map
// O(N) O(N)
class Solution {
    public int partitionArray(int[] nums, int k) {
        int ans = 0;
        boolean[] visit = new boolean[100_001];
        int prv = - k - 1;
        for (int num : nums) {
            visit[num] = true;
        }
        for (int i = 0; i < visit.length; ++i) {
            if (!visit[i]) {
                continue;
            }
            if (i - prv > k) {
                ++ans;
                prv = i;
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
