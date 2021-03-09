# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List
from collections import defaultdict

# dijkstra, dfs
# O(E*lgV) O(E+N)
class Solution:
    def countRestrictedPaths(self, n: int, edges: List[List[int]]) -> int:
        MOD = 1000000007
        if n == 1:
            return 0
        G = defaultdict(list)
        for u, v, w in edges:
            G[u].append((w,v))
            G[v].append((w,u))
        def dijkstra():
            pq = [(0, n)]
            dist = [float('inf')] * (n+1)
            dist[n] = 0
            while pq:
                d, u = heappop(pq)
                if d != dist[u]:
                    continue
                for w, v in G[u]:
                    if dist[v] > dist[u] + w:
                        dist[v] = dist[u] + w
                        heappush(pq, (dist[v], v))
            return dist
        @lru_cache(None)
        def dfs(u):
            if u == n:
                return 1
            ans = 0
            for _, v in G[u]:
                if dist[u] > dist[v]:
                    ans = (ans + dfs(v)) % MOD
            return ans
        dist = dijkstra()
        return dfs(1)        
        
if __name__ == "__main__":
    main()
