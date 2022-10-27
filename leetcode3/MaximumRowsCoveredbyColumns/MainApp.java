// Copyright (C) 2022 by iamslash

import java.util.*;

// 7ms 55.57% 41.1MB 92.71%
// bit manipulation
// O(H^2W) O(1)
class Solution {
    public int maximumRows(int[][] matrix, int numSelect) {
        int maxCnt = 0, h = matrix.length, w = matrix[0].length;
        for (int bm = 0; bm < (1 << w); ++bm) {
            if (Integer.bitCount(bm) != numSelect) {
                continue;
            }
            int curCnt = 0;
            for (int y = 0; y < h; ++y) {
                boolean taken = true;
                for (int x = 0; x < w; ++x) {
                    if ((bm >> x & 1) == 0 && matrix[y][x] == 1) {
                        taken = false;
                        break;
                    }
                }
                if (taken) {
                    curCnt++;
                }
            }
            maxCnt = Math.max(maxCnt, curCnt);
        }
        return maxCnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
