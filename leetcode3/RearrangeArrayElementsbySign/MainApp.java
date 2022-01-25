// Copyright (C) 2022 by iamslash

import java.util.*;

//       
//               i
// nums: 3 -2 1 -5 -4 2
//            j

// 9ms 71.88% 185.3MB 34.73%
// brute force
// O(N) O(N)
class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        int[] negNums = new int[n/2];
        int[] posNums = new int[n/2];
        for (int i = 0, j = 0, k = 0; i < n; ++i) {
            if (nums[i] > 0) {
                posNums[j++] = nums[i];
            } else {
                negNums[k++] = nums[i];
            }
        }
        for (int i = 0; i < n/2; ++i) {
            nums[i*2]   = posNums[i];
            nums[i*2+1] = negNums[i];
        }
        return nums;
    }
}

// 7ms 86.99% 186MB 30.39%
// O(N) O(N)
// two pointers
class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int j = 0, k = 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 0) {
                ans[j] = nums[i];
                j += 2;
            } else {
                ans[k] = nums[i];
                k += 2;
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
