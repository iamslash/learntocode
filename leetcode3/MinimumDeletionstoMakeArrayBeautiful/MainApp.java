// Copyright (C) 2022 by iamslash

import java.util.*;

//             i
// nums: 1 1 2 3 5

//                 i
// nums: 1 1 2 2 3 3
//  cnt: 1 

// 4ms 81.08% 99.9MB 39.70%
// brute force
// O(N) O(1)
class Solution {
    public int minDeletion(int[] nums) {
        int i = 0, n = nums.length, cnt = 0;
        while (i < n) {
            if ((i + 1 < n && nums[i] == nums[i+1]) ||
                i + 1 == n && (n - cnt) % 2 == 1) {
                cnt++;
                i += 1;
            } else {
                i += 2;
            }            
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
