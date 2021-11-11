// Copyright (C) 2021 by iamslash

import java.util.*;

// score of node a =
//   count of left subtree *
//   count of right subtree *
//   count of total - (1) - (count of left subtree) - (count of right subtree)

//                    i
//  parents: -1 2 0 2 0
// children:  0 2
//            2 1
//            4 3

// hash map
// O(N) O(N)
class Solution {
    private int best = 0;
    private int dfs(Map<Integer, List<Integer>> tree, int n, int u) {
        // base
        List<Integer> children = tree.get(u);
        if (children == null) {
            return 0;
        }
        // recursion
        int cnt = 1, prod = 1;
        for (Integer v : children) {
            int subCnt = dfs(tree, n, v);
            cnt += subCnt;
            prod *= subCnt;
        }
        if (n - cnt > 1) {
            prod *= (n - cnt);
        }
        best = Math.max(best, prod);
        return cnt;
    }
    public int countHighestScoreNodes(int[] parents) {
        Map<Integer, List<Integer>> tree = new HashMap<>();
        // build tree
        for (int u = 0; u < parents.length; ++u) {
            int p = parents[u];
            tree.putIfAbsent(p, new ArrayList<>());
            tree.get(p).add(u);
        }
        dfs(tree, parents.length, 0);
        return best;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
