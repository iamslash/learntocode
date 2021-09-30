// Copyright (C) 2021 by iamslash

import java.util.*;

// -5  1
// -1 -1
// -1  1
//  3 -1
//  0  1
//  6 -1

// 108ms 100.00% 91.3MB 100.00%
// sort
// O(NlgN) O(N)
class Solution {
    public int brightestPosition(int[][] lights) {
        int n = lights.length;
        int[][] events = new int[n*2][2];
        for (int i = 0; i < n; ++i) {
            events[i*2][0] = lights[i][0] - lights[i][1];
            events[i*2][1] = 1;
            events[i*2+1][0] = lights[i][0] + lights[i][1];
            events[i*2+1][1] = -1;
        }
        Arrays.sort(events, (a, b) -> {
                if (a[0] == b[0]) {
                    return b[1] - a[1];
                }
                return a[0] - b[0];
            });
        int maxPos = events[0][0], maxVal = 1;
        int curVal = 0;
        for (int[] evt : events) {
            curVal += evt[1];
            if (curVal > maxVal) {
                maxVal = curVal;
                maxPos = evt[0];
            }
        }
        return maxPos;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
