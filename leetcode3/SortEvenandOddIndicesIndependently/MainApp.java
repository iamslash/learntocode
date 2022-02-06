// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 4 1 2 3
// evns: 2 4
// odds: 1 3
// nums: 

// nums: 4 1 2 3 5
// evns: 2 4 5
// odds: 1 3
// nums: 

// 3ms 100.00% 45MB 25.00%
// sort
// O(NlgN) O(N)
class Solution {
    public int[] sortEvenOdd(int[] nums) {
        int n = nums.length, nEvns = (n+1)/2, nOdds = n/2;
        int[] odds = new int[nOdds];
        int[] evns = new int[nEvns];
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                evns[i/2] = nums[i];
            } else {
                odds[i/2] = nums[i];
            }
        }
        Arrays.sort(odds);
        Arrays.sort(evns);
        for (int i = 0; i < n; ++i) {
            // System.out.println(i);
            if (i % 2 == 0) {
                nums[i] = evns[i/2];
            } else {
                nums[i] = odds[nOdds - 1 - i/2];
            }
        }
        return nums;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
