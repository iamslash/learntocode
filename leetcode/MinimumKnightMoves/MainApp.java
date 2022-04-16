// Copyright (C) 2022 by iamslash

import java.util.*;

// 7ms 98.88% 41.8MB 98.97%
// recursive dynamic programming
// O(N^2) O(N)
class Solution {
    private int dfs(Map<Pair<Integer, Integer>, Integer> C, int x, int y) {
        // base
        x = Math.abs(x);
        y = Math.abs(y);
        if (x + y == 0) {
            return 0;
        }
        if (x + y == 2) {
            return 2;
        }
        // memo
        Pair pair = new Pair(x, y);
        if (C.containsKey(pair)) {
            return C.get(pair);
        }
        // recursion
        int minDist = 1 + Math.min(dfs(C, x-1, y-2), dfs(C, x-2, y-1));
        C.put(pair, minDist);
        return minDist;
    }
    public int minKnightMoves(int x, int y) {
        Map<Pair<Integer, Integer>, Integer> C = new HashMap<>();
        return dfs(C, x, y);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
