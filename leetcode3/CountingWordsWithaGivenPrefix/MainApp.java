// Copyright (C) 2022 by iamslash

import java.util.*;

// 2ms 28.57% 43.1MB 85.71%
// brute force
// O(N) (1)
class Solution {
    private boolean prefix(String word, String pref) {
        if (word.length() < pref.length()) {
            return false;
        }
        for (int i = 0; i < pref.length(); ++i) {
            if (word.charAt(i) != pref.charAt(i)) {
                return false;
            }
        }
        return true;                                                
    }
    public int prefixCount(String[] words, String pref) {
        int cnt = 0;
        for (String word : words) {
            if (prefix(word, pref)) {
                cnt++;
            }
        }
        return cnt;
    }
}

// 1ms 85.71% 43.9MB 28.57%
// brute force
// O(N) (1)
class Solution {
    public int prefixCount(String[] words, String pref) {
        int cnt = 0;
        for (String word : words) {
            if (word.startsWith(pref)) {
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
