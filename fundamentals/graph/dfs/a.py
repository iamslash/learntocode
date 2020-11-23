# -*- coding: utf-8 -*-
# Copyright (C) 2016 by iamslash
# > python3 a.py

import sys

g_n = 5
g_adj = []
g_discovered = []
g_counter = 0

def BuildGraph(n):
    global g_adj, g_discovered, g_counter

    g_adj = [[]] * n
    g_discovered = [-1] * n
    g_counter = 0

    g_adj[0].append(1)
    g_adj[1].append(2)
    g_adj[1].append(3)
    g_adj[2].append(3)

# 넓이 우선 탐색
def Dfs(here):
    global g_n, g_adj, g_discovered, g_counter
    
    print("%d"%(here))
    g_discovered[here] = g_counter
    g_counter += 1
    for i in range(len(g_adj[here])):
        there = g_adj[here][i]
        if (g_discovered[there] == -1):
            Dfs(there)

if __name__ == "__main__":   
    BuildGraph(g_n)

    # print("before BuildGraph")

    for i in range(g_n):
        if g_discovered[i] == -1:
            Dfs(i)
