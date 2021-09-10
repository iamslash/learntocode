// Copyright (C) 2021 by iamslash

import java.util.*;

//       i
// 1 3 7 0 0 0 0 1
//               j
//        i
// 1 3 12 0 0
//            j

// i
// 0
//   j

//     i
// 1 3 0 3 12
//          j

// 1ms 21.61% 41.9MB 17.70%
// two pointers
// O(N) O(1)
class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0, j = 0, n = nums.length;
        while (i < n && nums[i] != 0) {
            ++i;
        }
        j = i;
        while (j < n) {
            while (j < n && nums[j] == 0) {
                ++j;
            }
            // System.out.printf("i: %d, j: %d, n: %d\n", i, j, n);
            if (j < n) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                ++i;
            }
            // for (int num : nums) {
            //     System.out.printf("%d ", num);
            // }
            // System.out.println();
        }
    }
}

//       i
// 1 3 3 3 12
//          j

// 0ms 100.00% 41.8MB 20.29%
// two pointers
// O(N) O(1)
class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0, j = 0, n = nums.length;
        while (j < n) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                ++i;
            }
            ++j;
        }
        while (i < n) {
            nums[i++] = 0;
        }
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
