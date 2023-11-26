// Copyright (C) 2023 by iamslash

import java.util.*;

// mat:
// 1 2 1 2
// 5 5 5 5
// 6 3 6 3

// 1ms 100.00% 44.5MB 33.33%
// brute force
// O(HW) O(1)
class Solution {
    public boolean areSimilar(int[][] mat, int k) {
        int h = mat.length, w = mat[0].length;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                int z = (x + k) % w;
                if (y % 2 == 0) {
                    z = (x + w - (k % w)) % w;
                }
                if (mat[y][x] != mat[y][z]) {
                    return false;
                }
            }
        }
        return true;
    }
}
