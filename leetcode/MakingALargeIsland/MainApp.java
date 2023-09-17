// Copyright (C) 2023 by iamslash

import java.util.*;

// 164ms 30.63% 69.5MB 91.70%
// dfs
class Solution {
    private int getColor(int[][] grid, int y, int x) {
        int n = grid.length;
        if (y < 0 || y >= n || x < 0 || x >= n || grid[y][x] == 0) {
            return 0;
        }
        return grid[y][x];
    }
    private int paint(int[][] grid, int y, int x, int c) {
        // System.out.printf("(%2d, %2d), c: %d\n", y, x, c);
        int n = grid.length;
        // base
        if (y < 0 || y >= n || x < 0 || x >= n || grid[y][x] != 1) {
            return 0;
        }      
        grid[y][x] = c;
        // recursion
        return 1 +
            paint(grid, y-1, x, c) +
            paint(grid, y, x+1, c) +
            paint(grid, y+1, x, c) +
            paint(grid, y, x-1, c);            
    }
    public int largestIsland(int[][] grid) {
        int n = grid.length;
        int[] dirs = new int[]{-1, 0, 1, 0, -1};
        // {color:count}
        Map<Integer, Integer> cntMap = new HashMap<>(Map.of(0, 0));
        // Paint 
        boolean seaFound = false;
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                if (grid[y][x] == 1) {
                    int key = cntMap.size() + 10;
                    cntMap.put(key, paint(grid, y, x, key));
                } else if (grid[y][x] == 0) {
                    seaFound = true;
                }
            }
        }
        // System.out.println(seaFound);
        if (!seaFound) {
            return n * n;
        }
        // System.out.println(cntMap);
        // Traverse sea and update maxCell
        int maxCell = 0;
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                if (grid[y][x] == 0) {
                    int cellCnt = 0;
                    Set<Integer> colorSet = new HashSet<>();
                    for (int i = 0; i < 4; ++i) {
                        int ny = y + dirs[i], nx = x + dirs[i+1];
                        colorSet.add(getColor(grid, ny, nx));
                    }
                    for (int color : colorSet) {
                        cellCnt += cntMap.get(color);
                    }
                    maxCell = Math.max(maxCell, cellCnt + 1);
                }
            }
        }
        return maxCell;
    }
}
