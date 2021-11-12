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

// 139ms 53.19% 70.9MB 78.69%
// hash map
// O(N) O(N)
class Solution {
    private long bestCnt = 0;
    private long bestScore = 0;
    private long dfs(Map<Integer, List<Integer>> tree, int n, int u) {
        // System.out.printf("u: %d, bestScore: %d\n", u, bestScore);
        // base
        List<Integer> children = tree.get(u);
        // recursion
        long sumCnt = 1, prod = 1;
        if (children != null) {
            for (Integer v : children) {
                long subCnt = dfs(tree, n, v);
                sumCnt += subCnt;
                prod *= subCnt;
            }
        }
        if (n - sumCnt > 1) {
            prod *= (n - sumCnt);
        }
        if (prod > bestScore) {
            bestScore = prod;
            bestCnt = 0;
        } 
        if (prod == bestScore) {
            bestCnt++;
        }
        return sumCnt;
    }
    public int countHighestScoreNodes(int[] parents) {
        Map<Integer, List<Integer>> tree = new HashMap<>();
        // build tree
        for (int u = 1; u < parents.length; ++u) {
            int p = parents[u];
            tree.putIfAbsent(p, new ArrayList<>());
            tree.get(p).add(u);
            // System.out.printf("p: %d, u: %d\n", p, u);
        }
        dfs(tree, parents.length, 0);
        return (int)bestCnt;
    }
}


public class MainApp {
  public static void main(String[] args) {
  }
}
