// Copyright (C) 2021 by iamslash

// 0ms 100.00% 38.7MB 94.71%
// brute force
// O(N^2) O(1)
class Solution {
    public int numOfStrings(String[] patterns, String word) {
        int cnt = 0;
        for (String pattern : patterns) {
            if (word.indexOf(pattern) >= 0) {
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
