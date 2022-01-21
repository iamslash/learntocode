// Copyright (C) 2022 by iamslash

import java.util.*;

// BFS
class Solution {
    public int orangesRotting(int[][] grid) {
        int fresh = 0, h = grid.length, w = grid[0].length;
        Queue<Integer> q = new ArrayDeque<>();
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] == 1) {
                    fresh++;
                }
                if (grid[y][x] == 2) {
                    q.offer(y * 100 + x);
                }
            }
        }
        if (fresh == 0) {
            return 0;
        }
        int step = 0;
        int[] dirs = new int[]{-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Integer u = q.poll();
                int y = u / 100;
                int x = u % 100;
                for (int j = 0; j < 4; ++j) {
                    int ny = y + dirs[j], nx = x + dirs[j+1];
                    if (ny < 0 || nx >= h || nx < 0 || nx >= w || grid[ny][nx] != 1) {
                        continue;
                    }
                    grid[ny][nx] = 2;
                    fresh--;
                }
            }
            step++;
        }
        return fresh > 0 ? -1 : step;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
