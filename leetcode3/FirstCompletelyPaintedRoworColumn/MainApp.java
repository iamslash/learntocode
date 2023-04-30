// Copyright (C) 2023 by iamslash

import java.util.*;

// 4 3 5
// 1 2 6

// 18ms 100.00% 63.7MB 100.00%
// hash map
// O(HW) O(HW)
class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int h = mat.length, w = mat[0].length, n = arr.length;
        int[] rows = new int[h], cols = new int[w];
        int[][] coords = new int[n + 1][2];
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                coords[mat[y][x]][0] = y;
                coords[mat[y][x]][1] = x;
            }
        }
        for (int i = 0; i < n; ++i) {
            int y = coords[arr[i]][0], x = coords[arr[i]][1];
            if (++rows[y] == w || ++cols[x] == h) {
                return i;
            }
        }
        return -1;
    }
}
