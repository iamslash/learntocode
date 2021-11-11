// Copyright (C) 2021 by iamslash

import java.util.*;

// cnt: 3
//            i
//   s: a a a b c b b c c
//                      j

// 33ms 100.00% 39.2MB 100.00%
// sliding window
// O(N) O(1)
class Solution {
    public int equalCountSubstrings(String s, int count) {
        Set<Character> charSet = new HashSet<>();
        for (char c : s.toCharArray()) {
            charSet.add(c);
        }
        int substrCnt = 0, maxUniqGrpBnd = charSet.size();
        for (int uniqGrpBnd = 1; uniqGrpBnd <= maxUniqGrpBnd; ++uniqGrpBnd) {
            int[] freqs = new int[26];
            int substrLen = count * uniqGrpBnd, uniqGroupCnt = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (++freqs[s.charAt(i)-'a'] == count) {
                    ++uniqGroupCnt;
                }
                if (i >= substrLen && --freqs[s.charAt(i-substrLen)-'a'] == count - 1) {
                    --uniqGroupCnt;
                }
                if (uniqGroupCnt == uniqGrpBnd) {
                    substrCnt++;
                }
            }
        }
        return substrCnt;
    }
}
