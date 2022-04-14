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

// 1ms 99.89% 40.4MB 98.47%
// brute force
// O(N^2) O(1)
class Solution {
    public String minimizeResult(String s) {
        int n = s.length(), addIdx = s.indexOf('+');
        int minSum = Integer.MAX_VALUE;
        String minStr = "";
        for (int i = 0; i < addIdx; ++i) {
            for (int j = addIdx+2; j <= n; ++j) {
                String aStr = s.substring(0, i);
                String bStr = s.substring(i, addIdx);
                String cStr = s.substring(addIdx+1,j);
                String dStr = s.substring(j);
                int a = (i == 0) ? 1 : Integer.valueOf(aStr);
                int b = Integer.valueOf(bStr);
                int c = Integer.valueOf(cStr);
                int d = (j == n) ? 1 : Integer.valueOf(dStr);
                // System.out.printf("%d * (%d + %d) * %d\n", a, b, c, d);
                int sum = a * (b + c) * d;
                if (sum < minSum) {
                    minSum = sum;
                    StringBuilder minSb = new StringBuilder();
                    if (i > 0) {
                        minSb.append(aStr);
                    }
                    minSb.append("(");
                    minSb.append(bStr);
                    minSb.append("+");
                    minSb.append(cStr);
                    minSb.append(")");
                    if (j < n) {
                        minSb.append(dStr);
                    }
                    minStr = minSb.toString();
                }
            }
        }
        return minStr;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
