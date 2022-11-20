// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 2 3 4 5 6 6
//       5C3
//       

// 6ms 100.00% 39.7MB 100.00%
// brute force
// O(N^3) O(1)
class Solution {
    public int unequalTriplets(int[] nums) {
        int ans = 0, n = nums.length;
        for (int i = 0; i < n-2; ++i) {
            for (int j = i+1; j < n-1; ++j) {
                if (nums[i] == nums[j]) {
                    continue;
                }
                for (int k = j+1; k < n; ++k) {
                    if (nums[i] != nums[k] && nums[j] != nums[k]) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
}

// Idea: combinatorics
//
// Let's say there 4 kinds of numbers in M such as a, b, c, d
// Then all cases are
// M[a] * M[b] * M[c]
// M[a] * M[b] * M[d]
// M[a] * M[c] * M[d]
// M[b] * M[c] * M[d]
//
// left                    cnt                  right
// (0)                  * M[a] * (M[b] + M[c] + M[d])
// (M[a])               * M[b] * (M[c] + M[d])
// (M[a] + M[b])        * M[c] * (M[d])
// (M[a] + M[b] + M[c]) * M[d] * (0)

// 2ms 100.00% 42.4MB 25.00%
// combinatorics
// O(N) O(1)
class Solution {
    public int unequalTriplets(int[] nums) {
        int n = nums.length;
        int[] freqMap = new int[10001];
        for (int num : nums) {
            freqMap[num]++;
        }
        int ans = 0, left = 0, right = n;
        for (int a = 1; a <= 1000; ++a) {
            if (freqMap[a] == 0) {
                continue;
            }
            right -= freqMap[a];
            ans += left * freqMap[a] * right;
            left += freqMap[a];
        }
        return ans;
    }
}
