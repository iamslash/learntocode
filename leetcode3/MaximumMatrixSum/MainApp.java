// Copyright (C) 2022 by iamslash

import java.util.*;

//  1 -1
// -1 -1

// 10ms 14.29% 86.4MB 8.87%
// matrix
// O(N^2) O(1)
class Solution {
    public long maxMatrixSum(int[][] M) {
        int n = M.length, negCnt = 0;
        long absSum = 0, minVal = 1000000;
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                absSum += Math.abs(M[y][x]);
                if (M[y][x] < 0) {
                    negCnt++;
                }
                minVal = Math.min(minVal, Math.abs(M[y][x])); 
            }
        }
        if (negCnt % 2 == 0) {
            return absSum;
        }
        return absSum - 2 * minVal;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
