// Copyright (C) 2025 by iamslash

import java.util.*;


// nums: 3 9 2 1 7
//       -----
//         -----
//           -----
// 

// Wrong Answer for
//      nums: [0,0], k: 2
//    output: -1
// exptected: 0
//
// Idea:
// 
// The number occurs 1
// even if it occurs several times in a same window.
//
// hash map
// O(N) O(1)
class Solution {
    public int largestInteger(int[] nums, int k) {
        int n = nums.length;
        int[] freqs = new int[51];

        for (int i = 0; i < n; ++i) {
            if (i < k - 1) {
                freqs[nums[i]] += i + 1;
            } else if (i > n - k) {
                freqs[nums[i]] += n - i;
            } else {
                freqs[nums[i]] += k;
            }
        }

        int ans = -1;
        for (int a = 0; a < freqs.length; ++a) {
            if (freqs[a] == 1) {
                ans = a;
            }
        }

        return ans;
    }
}

// 4ms 100.00% 44.65MB 100.00%
// hash set
// O(N) O(N)
class Solution {

    public int largestInteger(int[] nums, int k) {

        int[] freqs = new int[51];

        for(int i = 0; i <= nums.length - k; i++) {
            Set<Integer> set = new HashSet<>();

            for(int j = i; j < i + k; j++) {
                set.add(nums[j]);
            }
            
            for(int key : set) {
                freqs[key]++;
            }
        }
        
        for(int i = 50; i >= 0; i--) {
            if(freqs[i] == 1) {
                return i;
            }
        }
        
        return -1;
    }
}
