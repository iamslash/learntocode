// Copyright (C) 2021 by iamslash

import java.util.*;

//         k: 1
//                    i
//         s: T F F T
//     freqs: T F
//            1 2
//   maxFreq: 2
// maxWndLen: 3

//         k: 1
//                          i
//         s: T T F T T F T T
//                  ---------
//     freqs: T F
//            4 2
//   maxFreq: 4
// maxWndLen: 5
    
// 10ms 94.59%% 45MB 39.35%
// hash map
// O(N) O(1)
class Solution {
    public int maxConsecutiveAnswers(String s, int k) {
        char[] freqs = new char[128];
        int maxFreq = 0, maxWndLen = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            maxFreq = Math.max(maxFreq, ++freqs[c]);
            if (maxWndLen - maxFreq < k) {
                ++maxWndLen;
            } else {
                --freqs[s.charAt(i - maxWndLen)];
            }
        }
        return maxWndLen;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
