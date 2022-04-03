// Copyright (C) 2022 by iamslash

import java.util.*;

// 0ms 100.00% 39MB 100.00%
// math
// O(1) O(1)
class Solution {
    public int minBitFlips(int start, int goal) {
        int cnt = 0;
        while (start > 0 || goal > 0) {
            int bs = start % 2;
            int bg = goal % 2;
            if (bs != bg) {
                cnt++;
            }
            start /= 2;
            goal /= 2;
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
