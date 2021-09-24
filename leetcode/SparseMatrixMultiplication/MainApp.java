// Copyright (C) 2021 by iamslash

// 0ms 100.00% 39.7MB 51.70%
// math
// O(HW) O(HW)
class Solution {
    public int[][] multiply(int[][] mat1, int[][] mat2) {
        int m = mat1.length, n = mat1[0].length, w = mat2[0].length;
        int[][] ans = new int[m][w]; 
        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (mat1[y][x] != 0) {
                    for (int j = 0; j < w; ++j) {
                        if (mat2[x][j] != 0) {
                            ans[y][j] += mat1[y][x] * mat2[x][j];
                        }
                    }
                }
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
