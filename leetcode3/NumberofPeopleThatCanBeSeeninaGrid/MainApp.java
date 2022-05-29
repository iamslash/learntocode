// Copyright (C) 2022 by iamslash

import java.util.*;

//                  i
// heights: 3 1 4 2 5
//                    j
//          2 1 2 1

// two pointers
// O(HW) O(1)
class Solution {
    public int[][] seePeople(int[][] heights) {
        int h = heights.length, w = heights[0].length;
        int[][] ans = new int[h][w];
        int i = 0, j = 1;
        for (int y = 0; y < h; ++y) {
            while (j < n) {
                // move j
                while (j < n && heights[y][i] < heights[y][j]) {
                    j++;
                }
                // move i
                while (i < j) {
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
