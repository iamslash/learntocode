// Copyright (C) 2022 by iamslash

import java.util.*;

//             i
// nums: 0 1 0 1 1 0 0
//                     j
//  ans: 1
// nums: 1 1 0 0 1
//                 i
//       1 1 0 0 1 1 1 0 0 1
//                         j
//  ans: 0
//
//             i  
//       0 1 1 0 1 0 1 1 0 1
//               

// sliding window
// O(N) O(N)
class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length, ones = 0, maxOnesInWnd = 0;
        for (int num : nums) {
            ones += num;
        }
        int nn = 2 * n;
        int[] circledNums = new int[nn];
        System.arraycopy(nums, 0, circledNums, 0, n);
        System.arraycopy(nums, 0, circledNums, n, n);
        for (int i = 0, onesInWnd = 0; i < nn; ++i) {
            if (i >= ones && circledNums[i-ones] == 1) {
                onesInWnd--;
            }
            if (circledNums[i] == 1) {
                onesInWnd++;
            }
            maxOnesInWnd = Math.max(maxOnesInWnd, onesInWnd);
        }
        return ones - maxOnesInWnd;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
