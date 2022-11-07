// Copyright (C) 2022 by iamslash

import java.util.*;

//        k: 4
//        s: p v j c c i
// maxFreqs: 

// 46ms 51.21% 48.4MB 54.85%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public int longestIdealString(String s, int k) {
        // maxFreqs[c]: max freq ends with character 'c'
        int ans = 0, n = s.length(), maxFreqs[] = new int[256];
        for (int pos = 0; pos < n; ++pos) {
            int i = s.charAt(pos);
            for (int j = i - k; j <= i + k; ++j) {
                maxFreqs[i] = Math.max(maxFreqs[i], maxFreqs[j]);
            }
            ans = Math.max(ans, ++maxFreqs[i]);
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
