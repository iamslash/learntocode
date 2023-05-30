// Copyright (C) 2023 by iamslash

import java.util.*;

// 30ms 22.62% 45MB 14.62%
// hash set
// O(HW) O(HW)
class Solution {
    public int[][] differenceOfDistinctValues(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        int[][] ans = new int[h][w];
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                Set<Integer> tlSet = new HashSet<>();
                Set<Integer> brSet = new HashSet<>();
                int yy = y - 1, xx = x - 1;
                while (yy >= 0 && xx >= 0) {
                    tlSet.add(grid[yy][xx]);
                    yy--;
                    xx--;
                }
                yy = y + 1;
                xx = x + 1;
                while (yy < h && xx < w) {
                    brSet.add(grid[yy][xx]);
                    yy++;
                    xx++;
                }
                ans[y][x] = Math.abs(tlSet.size() - brSet.size());
            }
        }
        return ans;
    }
}
