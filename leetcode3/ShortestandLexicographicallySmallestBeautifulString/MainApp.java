// Copyright (C) 2023 by iamslash

import java.util.*;

//   k: 3
//              i
//   s: 100011001
// deq: 458

// 3ms 75.00% 41.1MB 100.00%
// sliding window
// O(N) O(N)
class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        Deque<Integer> deq = new ArrayDeque<>();
        int n = s.length(), minLen = 101;
        String minStr = "";
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (c == '1') {
                deq.addLast(i);
            } 
            if (deq.size() == k) {
                int beg = deq.getFirst();
                int end = deq.getLast();
                String subStr = s.substring(beg, end + 1);
                if ((end - beg + 1 == minLen && subStr.compareTo(minStr) < 0) ||
                    (end - beg + 1 < minLen)) {
                    minLen = end - beg + 1;
                    minStr = s.substring(beg, end + 1);
                }
                deq.removeFirst();
            }
        }
        return minStr;
    }
}
