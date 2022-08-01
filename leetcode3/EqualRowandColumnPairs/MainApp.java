// Copyright (C) 2022 by iamslash

import java.util.*;

// 89ms 36.91% 97.4MB 9.20%
// hash map
// O(HW) O(HW)
class Solution {
    public int equalPairs(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        Map<String, Integer> rowMap = new HashMap<>();
        StringBuilder[] colStrs = new StringBuilder[w];
        for (int x = 0; x < w; ++x) {
            colStrs[x] = new StringBuilder();
        }
        // This fills the sam StringBuilder.
        // Arrays.fill(colStrs, new StringBuilder());
        for (int y = 0; y < h; ++y) {
            StringBuilder rowStr = new StringBuilder();
            for (int x = 0; x < w; ++x) {
                rowStr.append('_');
                rowStr.append(Integer.toString(grid[y][x]));
                colStrs[x].append('_');
                colStrs[x].append(Integer.toString(grid[y][x]));
            }
            String key = rowStr.toString();
            rowMap.put(key, rowMap.getOrDefault(key, 0) + 1);
        }
        // System.out.println(rowMap);
        int ans = 0;
        for (int x = 0; x < w; ++x) {
            String key = colStrs[x].toString();
            // System.out.println(key);
            ans += rowMap.getOrDefault(key, 0);
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
