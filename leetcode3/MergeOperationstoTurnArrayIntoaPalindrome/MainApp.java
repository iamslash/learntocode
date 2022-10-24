// Copyright (C) 2022 by iamslash

import java.util.*;

//       i
// nums: 4 3 2 1 2 3 1
//                   j

// 6ms60.69% 91.7MB 38.62%
// greedy, two pointers
// O(N) O(1)
class Solution {
    public int minimumOperations(int[] nums) {
        int i = 0, j = nums.length - 1, cnt = 0;
        while (i < j) {
            if (nums[i] < nums[j]) {
                if (i < j) {
                    nums[i+1] += nums[i];
                }
                cnt++;
                i++;
            } else if (nums[i] > nums[j]) {
                if (i < j) {
                    nums[j-1] += nums[j];
                }
                cnt++;
                j--;
            } else {
                i++;
                j--;
            }
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
