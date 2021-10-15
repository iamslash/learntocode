// Copyright (C) 2021 by iamslash

import java.util.*;

//       k: 1
//          i
//       s: a a
//            j
// freqMap: a
//          1 
//  maxLen: 0

// 2ms 99.11% 38.9MB 81.90%
// sliding window
// O(N) O(1)
class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int maxLen = 0, i = 0, j = 0, n = s.length(), uniqCnt = 0;
        int[] freqs = new int[128];
        while (j < n) {
            char c = s.charAt(j++);
            if (freqs[c] == 0) {
                uniqCnt++;
            }
            freqs[c]++;
            while (uniqCnt > k) {
                c = s.charAt(i++);
                freqs[c]--;
                if (freqs[c] == 0) {
                    uniqCnt--;
                }
            }
            maxLen = Math.max(maxLen, j - i);
        }
        return maxLen;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
