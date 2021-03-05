# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List
from collections import deque

# 10688ms 100.00% 216.3MB 100.00%
# dfs, bfs
# O(HW) O(HW)
class Solution(object):
    def findShortestPath(self, master: 'gridMaster') -> int:
        """
        :type master: gridMaster
        :rtype: int
        """
        dirs = {
            'U': (-1,0),
            'R': (0,1),
            'D': (1,0),
            'L': (0,-1),            
        }
        backs = {
            'U': 'D',
            'R': 'L',
            'D': 'U',
            'L': 'R',
        }
        graph = dict()
        def dfs(y, x):
            # base
            if (y, x) in graph:
                return
            # recursion
            graph[y, x] = master.isTarget()
            for dir, (dy, dx) in dirs.items():
                if master.canMove(dir):
                    master.move(dir)
                    dfs(y+dy, x+dx)
                    master.move(backs[dir])
        def bfs():
            visit = set()
            q = [(0,0)]
            step = 0
            while q:
                tmpq = []
                for y, x in q:
                    if (y, x) in visit:
                        continue
                    visit.add((y, x))
                    if graph[y, x]:
                        return step
                    for dy, dx in dirs.values():
                        ny, nx = y + dy, x + dx
                        if (ny, nx) in graph:
                            tmpq.append((ny, nx))
                q = tmpq
                step += 1                    
            return -1
        dfs(0, 0)
        return bfs()
        
if __name__ == "__main__":
    main()
