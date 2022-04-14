// Copyright (C) 2022 by iamslash

import java.util.*;

//     lights: 0,1 2,1 3,2
//
// requirement: 0 2 1 4 1
//  brightness: 1 3 2 2 1

// 6ms 100.00% 82.3MB 100.00%
// line sweeping
// O(N) O(N)
class Solution {
    public int meetRequirement(int n, int[][] lights, int[] req) {
        int[] brights = new int[n];
        // Build brights
        for (int[] light : lights) {
            int beg = Math.max(0, light[0] - light[1]);
            int end = light[0] + light[1] + 1;
            brights[beg]++;
            if (end < n) {
                brights[end]--;
            }
        }
        int cnt = 0, cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += brights[i];
            // System.out.printf("%d ", cur);
            if (cur >= req[i]) {
                cnt++;
            }
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
