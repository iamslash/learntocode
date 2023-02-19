// Copyright (C) 2023 by iamslash

import java.util.*;

// Disjoint Set
// O(N) O(N)
class DisjointSet {
    int[] prnts;
    public DisjointSet(int n) {
        prnts = new int[n];
        Arrays.fill(prnts, -1);
    }
    public int find(int a) {
        if (prnts[a] >= 0) {
            return prnts[a] = find(prnts[a]);
        }
        return a;
    }
    public boolean merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (prnts[a] <= prnts[b]) {
            prnts[a] += prnts[b];
            prnts[b] = a;
        } else {
            prnts[b] += prnts[a];
            prnts[a] = b;
        }
        return true;
    }
}
class Solution {
    public int numberOfGoodPaths(int[] vals, int[][] edges) {
        int n = vals.length, ans = 0;
        List<Integer>[] graph = new ArrayList[n];
        // { val : nodes }
        Map<Integer, ArrayList<Integer>> valNodesMap = new TreeMap<>();
        for (int i = 0; i < n; ++i) {
            graph[i] = new ArrayList<>();
            valNodesMap.putIfAbsent(vals[i], new ArrayList<>());
            valNodesMap.get(vals[i]).add(i);
        }
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            if (vals[u] >= vals[v]) {
                graph[u].add(v);
            } else {
                graph[v].add(u);
            }
        }
        DisjointSet ds = new DisjointSet(n);
        for (int key : valNodesMap.keySet()) {
            for (int u : valNodesMap.get(key)) {
                for (int v : graph[u]) {
                    ds.merge(u, v);
                }
            }
            Map<Integer, Integer> grpMap = new HashMap<>();
            for (int u : valNodesMap.get(key)) {
                grpMap.put(ds.find(u), grpMap.getOrDefault(ds.find(u), 0) + 1);
            }
            ans += valNodesMap.get(key).size();
            for (int grp : grpMap.keySet()) {
                int size = grpMap.get(grp);
                ans += size * (size - 1) / 2;
            }
        }
        return ans;
    }
}
