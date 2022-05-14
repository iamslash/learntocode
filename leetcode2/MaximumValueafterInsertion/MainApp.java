// Copyright (C) 2022 by iamslash

import java.util.*;

// x: 9
// n: 99
//    999

// x: 2
// n: -13
//    -

// x: 3
// n: 123
//    3

// x: 3
// n: -132
//     

// 8ms 97.64% 42.9MB 96.62%
// brute force
// O(N) O(1)
class Solution {
    public String maxValue(String numStr, int x) {
        boolean neg = numStr.charAt(0) == '-';
        int n = numStr.length(), i = 0;
        String ans;
        if (neg) {
            for (i = 1; i < n; ++i) {
                if (numStr.charAt(i) - '0' > x) {
                    break;
                }
            }
        } else {
            for (i = 0; i < n; ++i) {
                if (numStr.charAt(i) - '0' < x) {
                    break;
                }
            }
        }        
        return String.format("%s%d%s", numStr.substring(0, i),
                            x, numStr.substring(i)); 
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
