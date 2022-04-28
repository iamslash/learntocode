// Copyright (C) 2022 by iamslash

import java.util.*;

// 2 5 4
// 1 5 1
//       i
// topSum: 0
// botSum: 7
//    ans: 4

// Idea:
//
// * * t t
// b * * *
//
//      *: trace of 1st robot 
// sum(t): top sum
// sum(b): bottom sum
//    ans: min(ans, max(sum(t), sum(b)))

// 3ms 97.16% 58.3MB 83.69%
// brute force
// O(N) O(1)
class Solution {
    public long gridGame(int[][] grid) {
        long topSum = 0, bottomSum = 0, ans = Long.MAX_VALUE;
        int w = grid[0].length;
        for (int i = 0; i < w; ++i) {
            topSum += grid[0][i];
        }
        for (int i = 0; i < w; ++i) {
            topSum -= grid[0][i];
            // System.out.printf("topSum: %d, botSum: %d, ans: %d\n", topSum, bottomSum, ans);
            ans = Math.min(ans, Math.max(topSum, bottomSum));
            bottomSum += grid[1][i];            
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
