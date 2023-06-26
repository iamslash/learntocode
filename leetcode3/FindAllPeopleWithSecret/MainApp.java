// Copyright (C) 2023 by iamslash

import java.util.*;

// 64ms 94.22% 107.7MB 56.20%
// disjoint set
// O(NlgN) O(N)
class DisjointSet {
    private int[] prnts;
    public DisjointSet(int n) {
        prnts = new int[n];
        for (int i = 0; i < n; ++i) {
            prnts[i] = i;
        }
    }
    public void merge(int u, int v) {
        prnts[find(v)] = find(u);
    }
    public int find(int u) {
        return prnts[u] == u ? u : (prnts[u] = find(prnts[u]));
    }
    public void reset(int u) {
        prnts[u] = u;
    }
}
class Solution {
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        Arrays.sort(meetings, (a, b) -> a[2] - b[2]);
        DisjointSet ds = new DisjointSet(n);
        ds.merge(0, firstPerson);
        int m = meetings.length, i = 0;
        while (i < m) {
            List<Integer> pool = new ArrayList<>();
            int ts = meetings[i][2];
            while (i < m && ts == meetings[i][2]) {
                int u = meetings[i][0];
                int v = meetings[i][1];
                ds.merge(u, v);
                pool.add(u);
                pool.add(v);
                i++;
            }
            for (int u : pool) {
                if (ds.find(0) != ds.find(u)) {
                    ds.reset(u);
                }
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int u = 0; u < n; ++u) {
            if (ds.find(0) == ds.find(u)) {
                ans.add(u);
            }
        }
        return ans;
    }
}
