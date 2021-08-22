// Copyright (C) 2021 by iamslash

import java.util.*;

//      t: ABC
//               l
//      s: ADOBECODEBANC
//                    r
//  freqs: A B C D O E N
//         0 0 1-1-1-1 0
//    cnt: 1
// wndIdx: 0
// wndLen: 6

//      t: ABC
//                   l
//      s: ADOBECODEBANC
//                      r
//  freqs: A B C D O E N
//         0 1 0-2-2-2 1
//    cnt: 1
// wndIdx:11
// wndLen: 4

// 2ms 95.67% 38.8MB 95.24%
// hash table
// O(N) O(N)
class Solution {
    public String minWindow(String s, String t) {
        int[] freqs = new int[128];
        for (char c : t.toCharArray()) {
            freqs[c]++;
        }
        int cnt = t.length(), l = 0, r = 0;
        int wndIdx = -1, wndLen = Integer.MAX_VALUE;
        while (r < s.length()) {
            if (freqs[s.charAt(r++)]-- > 0) {
                cnt--;
            }
            System.out.printf("l:%2d r:%2d c:%2d\n", l, r, cnt);            
            while (cnt == 0) {
                if (r - l < wndLen) {
                    wndIdx = l;
                    wndLen = r - l;
                }
                if (freqs[s.charAt(l++)]++ == 0) {
                    cnt++;
                }
                System.out.printf("  l:%2d r:%2d c:%2d\n", l, r, cnt);
            }
        }
        return wndIdx < 0 ? "" : s.substring(wndIdx, wndIdx + wndLen);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
