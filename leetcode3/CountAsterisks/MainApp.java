// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 100.00% 40.2MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public int countAsterisks(String s) {
        int barCnt = 0, starCnt = 0;
        for (char c : s.toCharArray()) {
            if (c == '|') {
                barCnt++;
            } else if (c == '*' && barCnt % 2 == 0) {
                starCnt++;
            }
        }
        return starCnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
