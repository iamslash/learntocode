// Copyright (C) 2021 by iamslash

import java.util.*;

// cnt: 3
//            i
//   s: a a a b c b b c c
//                      j

class Solution {
    public int equalCountSubstrings(String s, int count) {
        Set<Character> charSet = Set.of(s.toCharArray());
        int ans = 0, uniqBnd = charSet.size();
        for (int uniq = 1; uniq <= uniqBnd; ++uniq) {
            int[] freqs = new int[26];
            int maxUniqCharCnt = count * uniq, uniqCharCnt = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (++freqs[s.charAt(i) - 'a'] == count) {
                    ++uniqCharCnt;
                }
                if (i >= maxUniqCharCnt && --freqs[s[i-maxUniqCharCnt]-'a'] == count - 1) {
                    --uniqCharCnt;
                }
                ans += uniqCharCnt == uniq;
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
