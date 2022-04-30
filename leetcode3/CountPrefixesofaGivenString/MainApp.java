// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 100.00% 44MB 33.33%
// brute force
// O(N) O(1)
class Solution {
    public int countPrefixes(String[] words, String s) {
        int cnt = 0;
        for (String word : words) {
            if (s.startsWith(word)) {
                cnt++;
            }
        }
        return cnt;        
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
