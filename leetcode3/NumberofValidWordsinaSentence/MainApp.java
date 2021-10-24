// Copyright (C) 2021 by iamslash

import java.util.*;

// 8ms 60.00% 41.4MB 30.00%
// brute force
// O(N) O(1)
class Solution {
    private boolean validWord(String word) {
        int n = word.length(), hypenCnt = 0, puncCnt = 0;
        for (int i = 0; i < n; ++i) {
            char c = word.charAt(i);
            if ((c >= '0' && c <= '9')) {
                return false;
            }
            if ((c >= 'a' && c <= 'z') ||
                (c == '-') || (c == '!') || (c == '.') || (c == ',')) {
                // check hypen
                if (c == '-') {
                    if (i == 0 || i == n-1 || ++hypenCnt > 1) {
                        return false;
                    }
                    if (i-1 >= 0 && !Character.isLetter(word.charAt(i-1))) {
                        return false;
                    }
                    if (i+1 < n && !Character.isLetter(word.charAt(i+1))) {
                        return false;
                    }
                }
                // check puntationMark
                if (c == '!' || c == '.' || c == ',') {
                    if (i != n-1 || ++puncCnt > 1) {
                        return false;
                    }
                }
            } else {
                return false;
            }
        }
        return true;
    }
    public int countValidWords(String sentence) {
        
        int cnt = 0;
        String[] words = sentence.split(" ");
        for (String word : words) {
            if (!word.trim().isEmpty() && validWord(word)) {
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
