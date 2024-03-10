// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: slding window, hash map
//
// freqs, cnt
// minWndIdx, minWndLen
// while (r < n) {
//   Traverse right index
//   while (cnt == 0) {
//     Update minWndIdx, minWndLen
//     Travere left index
//   }
// }
// return s.substring(minWndIdx, minWndIdx + minWndLen)
//
// When cnt == 0, The window has characters of t.
//   It's time to move left index.
//
//         t: ABC
//                      l
//         s: ADOBECODEBANC
//                         r
//     freqs: A B C D O E N
//            0-1 0 0 0 0-1
//       cnt: 1
// minWndIdx: 9
// minWndLen: 4

// 12ms 68.31% 44.7MB 63.59%
// sliding window, hash map
// O(S + T) O(T)
class Solution {
    public String minWindow(String s, String t) {
        int n = s.length(), m = t.length();
        Map<Character, Integer> freqMap = new HashMap<>();
        for (char c : t.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }
        int cnt = m, l = 0, r = 0;
        int minWndIdx = -1, minWndLen = Integer.MAX_VALUE;

        while (r < n) {
            char rChar = s.charAt(r++);
            if (freqMap.containsKey(rChar)) {
                freqMap.put(rChar, freqMap.get(rChar) - 1);
                if (freqMap.get(rChar) >= 0) {
                    cnt--;
                }
            }
            while (cnt == 0) {
                if (r - l < minWndLen) {
                    minWndIdx = l;
                    minWndLen = r - l;
                }
                char lChar = s.charAt(l++);
                if (freqMap.containsKey(lChar)) {
                    if (freqMap.get(lChar) == 0) {
                        cnt++;
                    }
                    freqMap.put(lChar, freqMap.get(lChar) + 1);
                }
            }
        }

        if (minWndIdx < 0) {
            return "";
        }
        return s.substring(minWndIdx, minWndIdx + minWndLen);
    }
}

// 3ms 77.23% 43.3MB 98.55%
// sliding window, hash map
// O(S + T) O(T)
class Solution {
    public String minWindow(String s, String t) {
        int n = s.length(), m = t.length();
        int[] freqs = new int[128];
        for (char c : t.toCharArray()) {
            freqs[c]++;
        }

        int cnt = m, l = 0, r = 0;
        int minWndIdx = -1, minWndLen = Integer.MAX_VALUE;

        while (r < n) {
            char rChar = s.charAt(r++);
            if (freqs[rChar] > 0) {
                cnt--;
            }
            freqs[rChar]--;
            // System.out.printf("l:%2d r:%2d c:%2d\n", l, r, cnt);            

            while (cnt == 0) {
                if (r - l < minWndLen) {
                    minWndIdx = l;
                    minWndLen = r - l;
                }

                char lChar = s.charAt(l++);
                if (freqs[lChar] == 0) {
                    cnt++;
                }
                freqs[lChar]++;
                // System.out.printf("  l:%2d r:%2d c:%2d\n", l, r, cnt);
            }
        }

        if (minWndIdx < 0) {
            return "";
        }
        return s.substring(minWndIdx, minWndIdx + minWndLen);
    }
}
