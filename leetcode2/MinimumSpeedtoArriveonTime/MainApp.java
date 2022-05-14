// Copyright (C) 2022 by iamslash

import java.util.*;

// difficult
// 247ms 31.39% 108.7MB 10.15%
// binary search
// O(lgN) O(1)
class Solution {
    public int minSpeedOnTime(int[] dist, double hour) {
        int n = dist.length, lo = 1, hi = 10_000_000, ans = -1;
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            double sum = 0;
            for (int i = 0; i < n; ++i) {
                double time = (double)dist[i] / mi;
                if (i < n - 1) {
                    time = Math.ceil(time);
                }
                sum += time;
            }
            if (sum > hour) {
                lo = mi + 1;
            } else {
                ans = mi;
                hi = mi - 1;
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
