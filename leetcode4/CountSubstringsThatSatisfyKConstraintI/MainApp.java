// Copyright (C) 2024 by iamslash

import java.util.*;

// k: 2
//    i
// s: 1 0 1 0 1 0 1
//            j                

// 2ms 79.34% 42.1MB 72.76%
// brute force
// O(N^2) O(1)
class Solution {
    public int countKConstraintSubstrings(String s, int k) {
        int n = s.length(), cnt = 0;

        for (int i = 0; i < n; ++i) {

            int zeroCnt = 0, oneCnt = 0;
            for (int j = i; j < n; ++j) {

                if (s.charAt(j) == '0') {
                    zeroCnt++;
                } else {
                    oneCnt++;
                }

                if (oneCnt <= k || zeroCnt <= k) {
                    cnt++;
                } else {
                    break;
                }
            }
        }

        return cnt;
    }
}

// 1ms 100.00% 42.6MB 18.79%
// sliding window
// O(N) O(1)
class Solution {

    public int countKConstraintSubstrings(String s, int k) {
        int n = s.length, cnt = 0;
        int[] freqs = new int[2];
        int beg = 0, end = 0;

        while (end < n) {
            freqs[s.charAt(end) - '0']++;

            while (freqs[0] > k && freqs[1] > k) {
                freqs[s.charAt(beg++) - '0']--;
            }

            cnt += end - beg + 1;
            end++;
        }

        return cnt;
    }
}
