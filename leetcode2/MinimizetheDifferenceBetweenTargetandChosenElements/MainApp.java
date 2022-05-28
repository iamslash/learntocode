// Copyright (C) 2022 by iamslash

import java.util.*;

// 68ms 100.00% 47.9MB 88.08%
// recursive dynamic programming
// O(HW) O(HW)
// difficult
class Solution {
    private int dfs(Integer[][] C, List<TreeSet<Integer>> graph,
                    int y, int sum, int target) {
        int h = graph.size();
        // base
        if (y == h) {
            return Math.abs(sum - target);
        }        
        // memo
        if (C[y][sum] != null) {
            return C[y][sum];
        }
        // recursion
        int minDiff = Integer.MAX_VALUE;
        for (int num : graph.get(y)) {
            minDiff = Math.min(minDiff, dfs(C, graph, y + 1, sum + num, target));
            if (minDiff == 0 || sum + num > target) {
                break;
            }
        }
        return C[y][sum] = minDiff;
    }
    public int minimizeTheDifference(int[][] mat, int target) {
        int h = mat.length, w = mat[0].length;
        Integer[][] C = new Integer[h][4901];
        List<TreeSet<Integer>> graph = new ArrayList<>();
        for (int y = 0; y < h; ++y) {
            TreeSet<Integer> set = new TreeSet<>();
            for (int x = 0; x < w; ++x) {
                set.add(mat[y][x]);
            }
            graph.add(set);
        }
        return dfs(C, graph, 0, 0, target);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
