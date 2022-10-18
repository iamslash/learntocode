// Copyright (C) 2022 by iamslash

import java.util.*;

// 12 5
//  5 2
//  2 1

//                   i
// nums: 12 6 3 14 8
// prev: 12     14
//  cnt:  1      2

// 1ms 100.00% 42.7MB 54.41%
// greedy, math
// O(N) O(1)
class Solution {
    private int gcd(int a, int b) {
        if (a % b == 0) {
            return b;
        }
        return gcd(b, a % b);
    }
    public int minimumSplits(int[] nums) {
        int cnt = 0, prev = 1;
        for (int num : nums) {
            prev = gcd(num, prev);
            if (prev == 1) {
                cnt++;
                prev = num;
            } 
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
