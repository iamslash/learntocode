// Copyright (C) 2022 by iamslash

// 9ms 13.29% 126.5MB 30.21%
// matrix
// O(N) O(1)
class Solution {
    public int minCost(int[] startPos, int[] homePos, int[] rowCosts, int[] colCosts) {
        int cost = 0, y = startPos[0], x = startPos[1], z = homePos[0], w = homePos[1];
        while (y != z) {
            y += (z - y) / Math.abs(z - y);
            cost += rowCosts[y];
        }
        while (x != w) {
            x += (w - x) / Math.abs(w - x);
            cost += colCosts[x];
        }
        return cost;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
