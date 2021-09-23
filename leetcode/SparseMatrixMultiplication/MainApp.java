// Copyright (C) 2021 by iamslash

class Solution {
    public int[][] multiply(int[][] mat1, int[][] mat2) {
        int h = mat1.length, w = mat2[0].length;
        int[][] ans = new int[h][w]; 
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (mat1[y][x] != 0) {
                    for (int j = 0; j < h; ++j) {
                        if (mat2[j][y] != 0) {
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
