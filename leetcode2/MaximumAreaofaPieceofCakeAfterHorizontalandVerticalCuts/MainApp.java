// Copyright (C) 2022 by iamslash

import java.util.*;

// 18ms 64.99% 61.5MB 5.79%
// math
// O(HW) O(1)
class Solution {
    public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
        long MOD = 1_000_000_007;
        Arrays.sort(horizontalCuts);
        Arrays.sort(verticalCuts);
        long maxW = 1, maxH = 1;
        for (int i = 0; i < horizontalCuts.length; ++i) {
            int prevCut = i == 0 ? 0 : horizontalCuts[i-1];
            maxH = Math.max(maxH, horizontalCuts[i] - prevCut);
        }
        maxH = Math.max(maxH, h - horizontalCuts[horizontalCuts.length-1]);
        for (int i = 0; i < verticalCuts.length; ++i) {
            int prevCut = i == 0 ? 0 : verticalCuts[i-1];
            maxW = Math.max(maxW, verticalCuts[i] - prevCut);
        }
        maxW = Math.max(maxW, w - verticalCuts[verticalCuts.length-1]);        
        return (int)(maxW * maxH % MOD);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
