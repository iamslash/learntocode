# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

# 84ms 82.98% 19.5MB 43.42%
# dijkstra
# O(N) O(N)
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        G = collections.defaultdict(dict)
        for u, v, c in flights:
            G[u][v] = c
        pq = [(0, src, k+1)]
        while pq:
            c, u, ttl = heapq.heappop(pq)
            if u == dst:
                return c
            if ttl == 0:
                continue
            for v in G[u]:
                heapq.heappush(pq, (c + G[u][v], v, ttl-1))
        return -1
    
if __name__ == "__main__":
    main()
