// Copyright (C) 2025 by iamslash

import java.util.*;


// 1 2
// 3 4

// 1 2 3
// 4 5 6
// 7 8 9

// 1ms 100.00% 45.36MB 97.15%
// brute force
// O(HW) O(HW)
class Solution {
    public List<Integer> zigzagTraversal(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        List<Integer> ans = new ArrayList<>();
        boolean lastIncluded = false;
        
        for (int y = 0; y < h; ++y) {
            if (y % 2 == 0) {
                for (int x = 0; x < w; ++x) {
                    if (!lastIncluded) {
                        ans.add(grid[y][x]);
                        lastIncluded = true;
                    } else {
                        lastIncluded = false;
                    }
                }
            } else {
                for (int x = w - 1; x >= 0; --x) {
                    if (!lastIncluded) {
                        ans.add(grid[y][x]);
                        lastIncluded = true;
                    } else {
                        lastIncluded = false;
                    }                    
                }
            }
        }

        return ans;
    }
}

