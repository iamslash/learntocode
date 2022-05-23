// Copyright (C) 2022 by iamslash

import java.util.*;

//  caps: 2 3 4 5
// rocks: 1 2 4 4
// diffs: 1 1 0 1
//        0 1 1 1
//            i
// addit: -

// 19ms 100.00% 90.6MB 14.29%
// sort
// O(NlgN) O(N)
class Solution {
    public int maximumBags(int[] caps, int[] rocks, int additionalRocks) {
        int n = caps.length;
        int[] diffs = new int[n];
        for (int i = 0; i < n; ++i) {
            diffs[i] = caps[i] - rocks[i];
        }
        Arrays.sort(diffs);
        int i = 0;
        while (i < n) {
            if (diffs[i] > 0) {
                additionalRocks -= diffs[i];
                if (additionalRocks < 0) {
                    return i;
                }
            }
            i++;
        }
        return i;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
