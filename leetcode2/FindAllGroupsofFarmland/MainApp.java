// Copyright (C) 2021 by iamslash

import java.util.*;

// 36ms 19.57% 139.2MB 8.56%
// DFS
// O(HW) O(HW)
class Solution {
    private int maxY = 0;
    private int maxX = 0;
    private List<int[]> ans = new ArrayList<>();
    private void dfs(int[][] land, int y, int x) {
        int h = land.length, w = land[0].length;
        int dir[] = new int[]{-1, 0, 1, 0, -1};
        land[y][x] = 0;
        maxY = Math.max(maxY, y);
        maxX = Math.max(maxX, x);
        for (int i = 0; i < 4; ++i) {
            int ny = y + dir[i], nx = x + dir[i+1];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w || land[ny][nx] == 0) {
                continue;
            }
            dfs(land, ny, nx);
        }
    }
    public int[][] findFarmland(int[][] land) {
        int h = land.length, w = land[0].length;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (land[y][x] == 1) {
                    maxY = y;
                    maxX = x;
                    dfs(land, y, x);
                    ans.add(new int[]{y, x, maxY, maxX});
                }
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
}

// 7ms 85.79% 126.5MB 37.06%
// brute force
// O(HW) O(N)
class Solution {
    public int[][] findFarmland(int[][] land) {
        int h = land.length, w = land[0].length;
        List<int[]> ans = new ArrayList<>();
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (land[y][x] == 1 &&
                    (y == 0 || land[y-1][x] == 0) &&
                    (x == 0 || land[y][x-1] == 0)) {
                    int yy = y, xx = x;
                    while (yy < h && land[yy][x] == 1) {
                        yy++;
                    }
                    while (xx < w && land[y][xx] == 1) {
                        xx++;
                    }
                    ans.add(new int[]{y, x, yy-1, xx-1});
                    x = xx-1;
                }
            }
        }
        return ans.toArray(new int[0][]);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
