// Copyright (C) 2023 by iamslash

import java.util.*;

// k: 6
// s: 6 0 7 4 6 2
//        i
//    

// 8ms 69.04% 46.8MB 15.48%
// greedy
// O(N) O(1)
class Solution {
    public int minimumPartition(String s, int k) {
        int n = s.length(), cnt = 1;
        long num = 0;
        for (char c : s.toCharArray()) {
            num = 10 * num + c - '0';
            if (num > k) {
                cnt++;
                num = c - '0';
            }
            if (num > k) {
                return -1;
            }
        }
        return cnt;
    }
}
