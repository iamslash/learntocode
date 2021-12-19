// Copyright (C) 2021 by iamslash

import java.util.*;

// 1ms 50.00% 39MB 50.00%
// brute force
// O(N) (2)
class Solution {
    private boolean isPalindrome(String s) {
        int i = 0, j = s.length()-1;
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) {                
                return false;
            }
        }
        return true;
    }
    public String firstPalindrome(String[] words) {
        for (String word : words) {
            if (isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
