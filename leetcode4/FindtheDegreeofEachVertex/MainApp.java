// Copyright (C) 2026 by iamslash


// matrx:
// 0 1 1
// 1 0 1
// 1 1 0


// 1ms 100.00% 47.93MB 97.80%
// array
// O(NlgN) O(1)
class Solution {
    public int[] findDegrees(int[][] matrix) {
        int h = matrix.length;
        int w = matrix[0].length;
        int[] ans = new int[h];

        // 
        for (int y = 0; y < h; ++y) {
            int cnt = 0;
            for (int x = 0; x < w; ++x) {
                cnt += matrix[y][x];
            }
            ans[y] = cnt;
        }
        
        return ans;
    }
}
