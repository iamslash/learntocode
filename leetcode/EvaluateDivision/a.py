# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List
from collections import deque

# 32ms 67.68% 14.1MB 92.62%
# bfs
# N: number of euqations
# M: number of quries
# O(NM)
# O(V+E) = O(2N+N) = O(N)
class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        G = dict()
        def build_graph(eqations, values):
            def add_edge(u, v, cost):
                if u in G:
                    G[u].append((v, cost))
                else:
                    G[u] = [(v, cost)]
            for nodes, cost in zip(equations, values):
                u, v = nodes
                add_edge(u, v, cost)
                add_edge(v, u, 1/cost)
        def find_path(query):
            start, end = query
            if start not in G or end not in G:
                return -1.0
            bfsq = deque([(start, 1.0)])
            visit = set()
            while bfsq:
                u, prod = bfsq.popleft()
                # bfs end condition
                if u == end:
                    return prod
                visit.add(u)
                for v, cost in G[u]:
                    if v in visit:
                        continue
                    bfsq.append((v, prod*cost))
            return -1.0
        build_graph(equations, values)
        return [find_path(q) for q in queries]

if __name__ == "__main__":
    sln = Solution()
    # [6.00000,0.50000,-1.00000,1.00000,-1.00000]
    print(sln.calcEquation([["a","b"],["b","c"]], [2.0,3.0], [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]))
    # [3.75000,0.40000,5.00000,0.20000]
    print(sln.calcEquation([["a","b"],["b","c"],["bc","cd"]], [1.5,2.5,5.0], [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]))
    # [0.50000,2.00000,-1.00000,-1.00000]
    print(sln.calcEquation([["a","b"]], [0.5], [["a","b"],["b","a"],["a","c"],["x","y"]]))
