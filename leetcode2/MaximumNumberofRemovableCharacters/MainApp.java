// Copyright (C) 2022 by iamslash

import java.util.*;

//         s: abcacb
//            .. .
//         p: ab
// removable: 3 1 0
// 
//         s: abcbddddd
//             ......
//         p: abcd
// removable: 3 2 1 4 5 6

// difficult
// 125ms 71.11% 83.8MB 65.93%
// binary search, two pointers
// O(NlgN) O(1)
class Solution {
    private boolean subseq(char[] chars, String p) {
        int i = 0, j = 0;
        while (i < chars.length && j < p.length()) {
            char src = chars[i], dst = p.charAt(j);
            if (src != '/' && src == dst) {
                j++;
            }
            i++;
        }
        return j == p.length();
    }
    public int maximumRemovals(String s, String p, int[] removable) {
        char[] chars = s.toCharArray();
        int lo = 0, hi = removable.length;
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            for (int i = 0; i < mi; ++i) {
                chars[removable[i]] = '/';
            }
            if (subseq(chars, p)) {
                lo = mi + 1;
            } else {
                hi = mi - 1;
                // restore chars
                for (int i = 0; i < mi; ++i) {
                    chars[removable[i]] = s.charAt(removable[i]);
                }
            }
        }
        return hi;
    }
}
