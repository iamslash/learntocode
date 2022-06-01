// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea:
//
// The count of trailing zeros is same with the count of pairs(2, 5).

// 263ms 26.49% 171.9MB 7.55%
// partital sum
// O(HW) O(HW)
class Solution {
    private int[] getFactors(int num) {
        int factor2 = 0, factor5 = 0;
        while (num % 2 == 0) {
            num /= 2;
            factor2++;
        }
        while (num % 5 == 0) {
            num /= 5;
            factor5++;
        }
        return new int[]{factor2, factor5};
    }
    public int maxTrailingZeros(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        int[][][] rows = new int[h][w+1][2];
        int[][][] cols = new int[h+1][w][2];
        rows[0][0] = new int[]{0, 0};
        cols[0][0] = new int[]{0, 0};
        // Build rows, cols
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                int[] factors = getFactors(grid[y][x]);
                int factor2 = factors[0], factor5 = factors[1];
                rows[y][x+1] = new int[]{rows[y][x][0] + factor2, rows[y][x][1] + factor5};
                cols[y+1][x] = new int[]{cols[y][x][0] + factor2, cols[y][x][1] + factor5};
            }
        }
        // Get ans
        int ans = 0;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                int[] v1 = cols[y+1][x];
                int[] v2 = new int[]{cols[h][x][0] - cols[y][x][0], cols[h][x][1] - cols[y][x][1]};
                int[] h1 = rows[y][x];
                int[] h2 = new int[]{rows[y][w][0] - rows[y][x+1][0], rows[y][w][1] - rows[y][x+1][1]};
                // 4 cases
                ans = Math.max(ans, Math.min(v1[0] + h1[0], v1[1] + h1[1]));
                ans = Math.max(ans, Math.min(v1[0] + h2[0], v1[1] + h2[1]));
                ans = Math.max(ans, Math.min(v2[0] + h1[0], v2[1] + h1[1]));
                ans = Math.max(ans, Math.min(v2[0] + h2[0], v2[1] + h2[1]));
            }
        }
        return ans;
    }    
}

public class MainApp {
  public static void main(String[] args) {
  }
}
