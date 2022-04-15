// Copyright (C) 2022 by iamslash

import java.util.*;

// 230ms 52.09% 42.4MB 95.06%
// recursive dynamic programming
// O(HW) O(HW)
// H: height of the wall
// W: bitmask of width
class Solution {
    private final int MOD = 1_000_000_007;
    private int dfs(int[][] C, int h, int w, int[] bricks, int curBm, int curWidth, int prvBm) {
        // base
        if (h == 0) {
            return 1;
        }
        // memo
        if (C[h][prvBm] >= 0) {
            return C[h][prvBm];
        }
        // recursion
        if (curWidth == w) {
            return dfs(C, h-1, w, bricks, 0, 0, curBm);
        }
        int ans = 0;
        for (int brick : bricks) {
            int newWidth = curWidth + brick;
            if (newWidth > w) {
                continue;
            }
            int newBm = newWidth < w ? curBm | (1 << newWidth) : curBm;
            if ((newBm & prvBm) > 0) {
                continue;
            }
            ans = (ans + dfs(C, h, w, bricks, newBm, newWidth, prvBm)) % MOD;
        }
        return curBm == 0 ? C[h][prvBm] = ans : ans;
    }
    public int buildWall(int height, int width, int[] bricks) {
        int[][] C = new int[height+1][1<<width];
        for (int[] line : C) {
            Arrays.fill(line, -1);
        }
        return dfs(C, height, width, bricks, 0, 0, 0);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
