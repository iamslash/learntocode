// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 39.3MB 42.86%
// brute force
// O(N) O(N)
class Solution {
    private int maxNum(String s) {
        char[] chrs = s.toCharArray();
        int n = chrs.length;
        char src = (char)0;
        for (int i = 0; i < n; ++i) {
            if (src != (char)0 && chrs[i] == src) {
                chrs[i] = '9';
            } else if (src == (char)0 && chrs[i] != '9') {
                src = chrs[i];
                chrs[i] = '9';
            }            
            // System.out.printf("i: %d, src: %c, chrs[i]: %c\n", i, src, chrs[i]);
        }
        return Integer.parseInt(new String(chrs));
    }
    private int minNum(String s) {
        char[] chrs = s.toCharArray();
        int n = chrs.length;
        char src = (char)0;
        for (int i = 0; i < n; ++i) {
            if (src != (char)0 && chrs[i] == src) {
                chrs[i] = '0';
            } else if (src == (char)0 && chrs[i] != '0') {
                src = chrs[i];
                chrs[i] = '0';
            }
        }
        return Integer.parseInt(new String(chrs));
    }
    public int minMaxDifference(int num) {
        String s = Integer.toString(num);
        int n = s.length();
        // System.out.printf("max: %d, min: %d\n", maxNum(s), minNum(s));
        return maxNum(s) - minNum(s);
    }
}

//         i
//    num: 11891
//      v: 1
// digits: 19811
//             x
//         11891
//   diff: 99009

// brute force
// 1ms 100.00% 39.2MB 71.43%
// difficult
class Solution {
    public int minMaxDifference(int num) {
        List<Integer> digits = new ArrayList<>();
        int v = 9, diff = 0;
        for (int x = num; x > 0; x /= 10) {
            int d = x % 10;
            if (d < 9) {
                v = d;
            }
            digits.add(d);
        }
        Collections.reverse(digits);
        for (int x : digits) {
            diff = 10 * diff;
            if (x == digits.get(0)) {
                diff += x;
            }
            if (x == v) {
                diff += 9 - x;
            }
        }
        return diff;
    }
}
