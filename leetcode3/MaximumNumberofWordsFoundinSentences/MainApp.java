// Copyright (C) 2021 by iamslash

import java.util.*;

// 3ms 68.42% 40.6MB 47.06%
// brute force
// O(N) O(1)
class Solution {
    private int getWordCnt(String s) {
        int cnt = 1;
        for (char c : s.toCharArray()) {
            if (c == ' ') {
                cnt++;
            }
        }
        return cnt;
    }
    public int mostWordsFound(String[] sentences) {
        int maxWords = 0;
        for (String s : sentences) {
            maxWords = Math.max(maxWords, getWordCnt(s));
        }                                    
        return maxWords;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
