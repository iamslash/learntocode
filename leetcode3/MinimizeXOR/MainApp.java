// Copyright (C) 2022 by iamslash

import java.util.*;

//          i
// nums1: 0010, nums2: 1100
//     a:    2,     b:    2
//     x: 0011   

// 1ms 92.75% 40.6MB 83.81%
// bit manipulation
// O(1) O(1)
class Solution {
    public int minimizeXor(int num1, int num2) {
        int x = num1, a = Integer.bitCount(num1), b = Integer.bitCount(num2);
        for (int i = 0; i < 32; ++i) {
            if (a > b && ((1 << i) & num1) > 0) {
                x ^= (1 << i);
                a--;
            }
            if (a < b && ((1 << i) & num1) == 0) {
                x ^= (1 << i);
                a++;
            }
        }
        return x;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
