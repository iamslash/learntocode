// Copyright (C) 2023 by iamslash

import java.util.*;


// 0 0 0 0

// 0 1 0 1
// 1 0 1 1

// 0 1 1 0    
// 0 0 0 1    
// 1 1 1 1    

// 138ms 35.32% 55.4MB 49.15%
// greedy
// O(H^2W) O(N)
class Solution {
    public List<Integer> goodSubsetofBinaryMatrix(int[][] grid) {
        List<Integer> ans = new ArrayList();
        int h = grid.length, w = grid[0].length;
        // Return one row which zero masked.
        for (int y = 0; y < h; ++y) {
            boolean allzero = true;
            for (int x = 0; x < w; ++x) {
                if (grid[y][x] != 0) {
                    allzero = false;
                    break;
                }
            }
            if (allzero) {
                ans.add(y);
                return ans;
            }
        }
        // Return two rows which zero masked.
        for (int y = 0; y < h; ++y) {
            for (int yy = y + 1; yy < h; ++yy) {
                boolean allzero = true;
                for (int x = 0; x < w; ++x) {
                    if ((grid[y][x] & grid[yy][x]) > 0) {
                        allzero = false;
                        break;
                    }
                }
                if (allzero) {
                    ans.add(y);
                    ans.add(yy);
                    return ans;
                }
            }
        }
        // Return empty row.
        return ans;
    }
}

// greedy, bit manipulation
// 2ms 100.00% 55.4MB 49.15%
class Solution {
    public List<Integer> goodSubsetofBinaryMatrix(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        int[] bms = new int[33];
        for (int y = 0; y < h; ++y) {
            int val = 0;
            for (int x = w - 1; x >= 0; --x) {
                val = (val << 1) | grid[y][x];
            }
            for (int x = 0; x <= (1 << w); ++x) {
                if (bms[x] != 0 && (x & val) == 0) {
                    return Arrays.asList(bms[x] - 1, y);
                }
            }
            bms[val] = y + 1;
        }
        if (bms[0] != 0) {
            return Arrays.asList(bms[0] - 1);
        }
        return new ArrayList<>();
    }
}
