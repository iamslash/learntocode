// Copyright (C) 2022 by iamslash

import java.util.*;

//              i
// src: _L__R__R_
// dst: L______RR
//               j


//               i
// src: _L__R__R_L
// dst: L______RR_
//                j

//        i
// src: _L
// dst: LL
//       j

// 21ms 87.77% 54.9MB 59.11%
// two pointers
// O(N) O(1)
class Solution {
    public boolean canChange(String src, String dst) {
        // if (!src.replaceAll("_", "").equals(dst.replaceAll("_", ""))) {
        //     return false;
        // }
        int i = 0, j = 0, n = src.length();
        while (i < n && j < n) {
            while (i < n && src.charAt(i) == '_') {
                ++i;
            }
            while (j < n && dst.charAt(j) == '_') {
                ++j;
            }
            // System.out.printf("i: %d, j: %d\n", i, j);
            if (i >= n || j >= n) {
                break;
            }
            if (src.charAt(i) == 'L' && dst.charAt(j) == 'L') {
                if (i < j) {
                    return false;
                }
            } else if (src.charAt(i) == 'R' && dst.charAt(j) == 'R') {
                if (i > j) {
                    return false;
                }
            } else {
                return false;
            }
            i++;
            j++;
        }
        if ((i < n && src.charAt(i) != '_') ||
            (j < n && dst.charAt(j) != '_')) {
            return false;
        }
        return true;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
