// Copyright (C) 2022 by iamslash

import java.util.*;

// 2ms 87.50% 54.9MB 12.50%
// matrix
// O(HW) O(1)
class Solution {
    public boolean checkXMatrix(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (y == x || y == w-x-1) {
                    if (grid[y][x] == 0) {
                        return false;
                    }
                } else {
                    if (grid[y][x] != 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
