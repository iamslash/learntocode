// Copyright (C) 2022 by iamslash

import java.util.*;

// 6ms 67.48% 97.7MB 45.41%
// two pointers
// O(N) O(1)
class Solution {
    public long zeroFilledSubarray(int[] nums) {
        int n = nums.length, i = 0, j = 0;
        long ans = 0;
        while (i < n) {
            if (nums[i] != 0) {
                i++;
                continue;
            }
            j = i + 1;
            while (j < n && nums[j] == 0) {
                j++;
            }
            long diff = j - i;
            // System.out.println(diff);
            ans += (diff * (diff + 1) / 2);     
            i = j;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
