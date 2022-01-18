// Copyright (C) 2022 by iamslash

import java.util.*;

// 59ms 74.07% 60.1MB 75.31%
// binary search
// O(NlgN) O(1)
class Solution {
    public double equalizeWater(int[] buckets, int loss) {
        int n = buckets.length;
        double lo = 0, hi = 100_000, retention = (100.0-loss)/100.0;
        while (hi - lo > 0.00001) {
            double mi = lo + (hi - lo)/2;
            double have = 0, need = 0;
            for (int water : buckets) {
                if (water >= mi) {
                    have += water - mi;
                } else {
                    need += mi - water;
                }
            }
            if (have * retention >= need) {
                lo = mi;
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
