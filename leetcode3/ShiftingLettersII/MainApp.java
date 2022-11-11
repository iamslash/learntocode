// Copyright (C) 2022 by iamslash

import java.util.*;

//   s: a b c
// shf: 0,1,0 1,2,1 0,2,1
// mvs: 0 1 1 -2
// ans: a c e

// 8ms 91.53% 82.5MB 93.79%
// line weep
// O(N) O(N)
class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        int[] moves = new int[n + 1];
        StringBuilder ans = new StringBuilder();
        for (int[] shift : shifts) {
            if (shift[2] == 0) {
                moves[shift[0]] -= 1;
                moves[shift[1]+1] += 1;
            } else {
                moves[shift[0]] += 1;
                moves[shift[1]+1] -= 1;
            }
        }
        int delta = 0;
        for (int i = 0; i < n; ++i) {
            delta = (delta + moves[i]) % 26; 
            int idx = (s.charAt(i) - 'a') + delta;
            idx = (idx + 26) % 26;
            ans.append((char)('a' + idx));
        }
        return ans.toString();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
