// Copyright (C) 2021 by iamslash

import java.util.*;
// gcd(3, 3)

// 0ms 100.00% 38.5MB 28.57%
// math
class Solution {
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    public int findGCD(int[] nums) {
        int minNum = 1000, maxNum = 1;
        for (int num : nums) {
            minNum = Math.min(minNum, num);
            maxNum = Math.max(maxNum, num);
        }
        return gcd(maxNum, minNum);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
