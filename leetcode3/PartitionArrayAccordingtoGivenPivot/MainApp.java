// Copyright (C) 2022 by iamslash

import java.util.*;

// pivot: 10
//        
//  nums: 9 12 5 10 14 3 10
//                        

// pivot: 5
//             i
//  nums: 9 12 5 10 14 3 10
//                     j
//

// 7ms 87.78% 169.3MB 24.79%
// brute force
// O(N) O(N)
class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length, pivotCnt = 0, i = 0;
        int[] ans = new int[n];
        // build pivotCnt, front of ans
        for (int num : nums) {
            if (num < pivot) {
                ans[i++] = num;
            } else if (num == pivot) {
                pivotCnt++;
            }
        }
        // build middle of ans
        while (pivotCnt-- > 0) {
            ans[i++] = pivot;
        }
        // build back of ans
        for (int num : nums) {
            if (num > pivot) {
                ans[i++] = num;
            }
        }
        return ans;
    }
}

// pivot: 5
//                   i
//  nums: 9 12 5 10 14 3 10
//             j
//        
//   ans:
//               

// four pointers
// O(N) O(N)
class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length; 
        int[] ans = new int[n];
        int beg = 0, end = n-1;
        for (int i = 0, j = n-1; i < n; ++i, --j) {
            if (nums[i] < pivot) {
                ans[beg++] = nums[i];
            }
            if (nums[j] > pivot) {
                ans[end--] = nums[j];
            }
        }
        while (beg <= end) {
            ans[beg++] = pivot;
        }
        return ans;
    }
}
