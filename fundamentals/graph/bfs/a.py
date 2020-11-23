# -*- coding: utf-8 -*-
# Copyright (C) 2016 by iamslash
# > python3 a.py

import sys

adj = []
discovered = []
counter = 0

def BuildGraph(n):
    adj = []    
    for i in range(n):
        adj.append([])
    discovered = []
    counter = 0
    
# 넓이 우선 탐색
def Bfs(n):
    discovered = l
    return [0, 1, 2, 4]

def PrintL(l):
    [print(i, end=" ") for i in l]
    
if __name__ == "__main__":
    adj[0].append(1)
    adj[1].append(2)
    adj[1].append(3)
    adj[2].append(3)

    r = Bfs(0)

    PrintL(r)
