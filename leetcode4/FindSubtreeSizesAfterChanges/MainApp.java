// Copyright (C) 2025 by iamslash

import java.util.*;

// Time Limit Exeed
// brute force
// O(N^2) O(N)
class Solution {
    public int[] findSubtreeSizes(int[] parents, String s) {
        int n = parents.length;
        int[] newParents = new int[n];
        newParents[0] = -1;
        int[] ans = new int[n];
        Arrays.fill(ans, 1);

        // Update newParents
        for (int i = 1; i < n; ++i) {
            int curParent = parents[i];
            newParents[i] = curParent;

            while (curParent != -1 &&
                   s.charAt(curParent) != s.charAt(i)) {
                curParent = parents[curParent];
            }

            if (curParent != -1) {
                newParents[i] = curParent;
            }
        }

        // Update ans
        for (int i = 1; i < n; ++i) {
            int curParent = newParents[i];

            while (curParent != -1) {
                ans[curParent]++;
                curParent = newParents[curParent];
            }
        }

        return ans;
    }
}


// Idea: dfs
//
//           0a
//        /     \
//      1b      2a
//   /  |  \
// 3a  4b  5c
//
//
// lastParents: 0 1 2 3 4 5
//              0 1 2 3 4 5
//              u
//     parents: - 0 0 1 1 1
//         ans: 5 4 1 1 1 1

// 170ms 84.21% 113.26MB 40.00%
// dfs
// O(N) O(N)
class Solution {

    private void dfs(int[] parents, String s, int[] ans,
                     List<List<Integer>> graph, int[] lastParents,
                     int u) {
        // base
        int pos = s.charAt(u) - 'a';
        if (lastParents[pos] != -1) {
            parents[u] = lastParents[pos];
        }
        lastParents[pos] = u;
                
        // recursion
        for (int v : graph.get(u)) {
            dfs(parents, s, ans, graph,
                Arrays.copyOf(lastParents, lastParents.length), v);
        }

        if (parents[u] >= 0) {
            ans[parents[u]] += ans[u];
        }
    }
    
    public int[] findSubtreeSizes(int[] parents, String s) {
        int n = parents.length;
        int[] ans = new int[n];
        int[] lastParents = new int[26];

        Arrays.fill(ans, 1);
        Arrays.fill(lastParents, -1);

        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            graph.add(new ArrayList<>());
        }
        for (int u = 1; u < n; ++u) {
            graph.get(parents[u]).add(u);
        }

        dfs(parents, s, ans, graph, lastParents, 0);

        return ans;
    }
}
