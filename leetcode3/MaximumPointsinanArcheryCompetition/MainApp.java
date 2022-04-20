// Copyright (C) 2022 by iamslash

import java.util.*;

//   numArrows: 9
//
// aliceArrows: 1 1 0 1 0 0 2 1 0 1 2 0
//              

// 6ms 84.35% 43.2MB 55.60%
// backtracking
// O(2^N) O(N)
class Solution {
    // Best
    int maxBobPoint = 0;
    int[] maxBobArrows = new int[12];
    private void dfs(int[] aliceArrows, int[] bobArrows, int bobPoint,
                     int remained, int pos) {
        // base
        if (pos < 0 || remained <= 0) {
            if (remained > 0) {
                bobArrows[0] += remained;
            }
            if (bobPoint > maxBobPoint) {
                maxBobPoint = bobPoint;
                maxBobArrows = bobArrows.clone();
            }
            return;
        }
        // recursion
        int used = aliceArrows[pos] + 1;
        if (remained >= used) {
            bobArrows[pos] = used;
            dfs(aliceArrows, bobArrows, bobPoint + pos, remained - used, pos - 1);
            bobArrows[pos] = 0;
        }
        dfs(aliceArrows, bobArrows, bobPoint, remained, pos - 1);
        bobArrows[pos] = 0;
    }
    public int[] maximumBobPoints(int numArrows, int[] aliceArrows) {
        int[] bobArrows = new int[12];
        dfs(aliceArrows, bobArrows, 0, numArrows, 11);
        return maxBobArrows;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
