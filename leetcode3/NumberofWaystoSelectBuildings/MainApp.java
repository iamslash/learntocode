// Copyright (C) 2022 by iamslash

import java.util.*;

// s: 001101
//    0 1 0
//    0  10
//     01 0
//     0 10
//      1 01
//       101

// Time Limit Exceeded
// brute force
// O(N^3) O(1)
class Solution {
    public long numberOfWays(String s) {
        int n = s.length(), cnt = 0;
        for (int i = 0; i < n-2; ++i) {
            for (int j = i+1; j < n-1; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    continue;
                }
                for (int k = j+1; k < n; ++k) {
                    if (s.charAt(j) == s.charAt(k)) {
                        continue;
                    }
                    cnt++;
                }
            }
        }
        return cnt;
    }
}

// 51ms 68.98& 63.2MB 68.16%
// math
// O(N) O(1)
class Solution {
    public long numberOfWays(String s) {
        long n = s.length(), cnt = 0;
        long leftZeroCnt = s.charAt(0) == '0' ? 1 : 0, rightZeroCnt = 0;
        long leftOneCnt = s.charAt(0) == '1' ? 1 : 0, rightOneCnt = 0;
        for (int i = 1; i < n; ++i) {
            char c = s.charAt(i);
            rightZeroCnt += c == '0' ? 1 : 0;
            rightOneCnt += c == '1' ? 1 : 0; 
        }
        // System.out.printf("leftZeroCnt: %d, rightZeroCnt: %d\n", leftZeroCnt, rightZeroCnt);
        // System.out.printf("leftOneCnt: %d, rightOneCnt: %d\n", leftOneCnt, rightOneCnt);
        for (int i = 1; i < n-1; ++i) {
            if (s.charAt(i) == '0') {
                cnt += leftOneCnt * rightOneCnt;
                leftZeroCnt++;
                rightZeroCnt--;
            } else {
                cnt += leftZeroCnt * rightZeroCnt;
                leftOneCnt++;
                rightOneCnt--;
            }
        }        
        return cnt;
    }
}

//
// s: 001101
//    0 1 0
//    0  10
//     01 0
//     0 10
//      1 01
//       101

// 22ms 98.30% 68.4MB 59.62%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public long numberOfWays(String s) {
        long _01 = 0;
        long _10 = 0;
        long _0 = 0;
        long _1 = 0;
        long cnt = 0;
        for (char c : s.toCharArray()) {
            if (c == '0') {
                cnt += _01;
                _0++;
                _10 += _1;
            } else {
                cnt += _10;
                _1++;
                _01 += _0;
            }
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
