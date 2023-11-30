// Copyright (C) 2023 by iamslash

import java.util.*;

// 2ms 100.00% 43.2MB 73.27%
// sort
// O(HlgH * WlgW)
class Solution {
    private int getMaxGap(int[] bars) {
        Arrays.sort(bars);
        int cnt = 2, rst = 2, n = bars.length;
        for (int i = 1; i < n; ++i) {
            cnt = (bars[i - 1] + 1 == bars[i]) ? cnt + 1: 2;
            rst = Math.max(rst, cnt);
        }
        return rst;
    }
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        int gap = Math.min(getMaxGap(hBars), getMaxGap(vBars));
        return gap * gap;
    }
}
