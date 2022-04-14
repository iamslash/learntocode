// Copyright (C) 2022 by iamslash

import java.util.*;

// # Idea
//             i
// expression: 247+38
//                 j
//             (247+3)8 1 * (247 + 3) * 8
//             (247+38) 1 * (247 + 38)* 1
//             2(47+3)8 2 * (47  + 3) * 8
//             2(47+38) 2 * (47  + 38)* 1
//             24(7+3)8 24 
//             24(7+38) 24* (7   + 38)* 1

// brute force
// O(N^2) O(1)
class Solution {
    public String minimizeResult(String s) {
        int n = s.length(), addIdx = s.indexOf('+');
        int minSum = Integer.MAX_VALUE;
        for (int i = 0; i < addIdx - 1; ++i) {
            for (int j = addIdx+2; j <= n; ++j) {
                int a = (i == 0) ? 1 : Integer.valueOf(s.substring(0, i+1));
                int b = Integer.valueOf(s.substring(i, addIdx));
                int c = Integer.valueOf(s.substring(addIdx+1,j));
                int d = (j == n) ? 1 : Integer.valueOf(s.substring(j));
                int sum = a * (b + c) * d;
                minSum = Math.min(minSum, sum);
            }
        }
        return String.valueOf(minSum);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
