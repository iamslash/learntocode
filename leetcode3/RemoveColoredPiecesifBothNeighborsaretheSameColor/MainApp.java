// Copyright (C) 2021 by iamslash

import java.util.*;

//     
// colors: AAABABB
//   aCnt: 1
//   bCnt: 0

// 12ms 79.41% 40.4MB 69.87%z
// brute force
// O(N) O(1)
class Solution {
    public boolean winnerOfGame(String colors) {
        int n = colors.length(), aCnt = 0, bCnt = 0;
        for (int i = 1; i < n-1; ++i) {
            char prev = colors.charAt(i-1);
            char curr = colors.charAt(i);
            char next = colors.charAt(i+1);
            if (prev == curr && curr == next) {
                if (curr == 'A') {
                    aCnt++;
                } else {
                    bCnt++;
                }
            }
        }
        return aCnt > bCnt;
    }
}

// 7ms 97.86% 40.2MB 77.19%
// brute force
// O(N) O(1)
class Solution {
    public boolean winnerOfGame(String colors) {
        int n = colors.length(), aCnt = 0, bCnt = 0;
        char[] colorArr = colors.toCharArray();
        for (int i = 1; i < n-1; ++i) {
            if (colorArr[i-1] == colorArr[i] && colorArr[i] == colorArr[i+1]) {
                if (colorArr[i] == 'A') {
                    aCnt++;
                } else {
                    bCnt++;
                }
            }
        }
        return aCnt > bCnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
