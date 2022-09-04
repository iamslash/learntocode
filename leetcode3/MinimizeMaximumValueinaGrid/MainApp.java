// Copyright (C) 2022 by iamslash

import java.util.*;

// grid:
// 3 1
// 2 5
// 
// pq: 1 2 3 5
// maxRows:
// maxCols:

// 289ms 21.49% 98.3MB 83.18%
// priority queue
// O(HW*lgHW) O(HW)
class Solution {
    public int[][] minScore(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        Queue<int[]> pq = new PriorityQueue<>((a, b) -> grid[a[0]][a[1]] - grid[b[0]][b[1]]);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                pq.offer(new int[]{i, j});
            }
        }
        int[] maxRows = new int[h], maxCols = new int[w];
        int[][] ans = new int[h][w];
        while (pq.size() > 0) {
            int[] item = pq.poll();
            int row = item[0], col = item[1];
            int maxVal = Math.max(maxRows[row], maxCols[col]) + 1;
            ans[row][col] = maxVal;
            maxRows[row] = maxVal;
            maxCols[col] = maxVal;
        }
        return ans;
    }
}
