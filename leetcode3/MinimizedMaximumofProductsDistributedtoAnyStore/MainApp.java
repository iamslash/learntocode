// Copyright (C) 2022 by iamslash

import java.util.*;

//           n: 3
// quantitiles: 20 1

// 52ms 89.17% 94.3MB 43.19%
// binary search
// O(NlgN) O(1)
class Solution {
    public int minimizedMaximum(int n, int[] quantities) {
        int lo = 1, hi = 100_000;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2, cnt = 0;
            for (int q : quantities) {
                cnt += (q + mi - 1) / mi;
            }
            if (cnt > n) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        return lo;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
