# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List
from collections import deque

# isWater:
# 0 1
# 0 0
#
# matrix:
# 1 0
# - -

# 3840ms 100.00% 79.4MB 100.00%
# bfs
# O(HW) O(HW)
class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        h, w = len(isWater), len(isWater[0])
        matrix = [[-1] * w for _ in range(h)]
        bfsq = deque()
        for y in range(h):
            for x in range(w):
                if isWater[y][x] == 1:
                    bfsq.append((y,x))
                    matrix[y][x] = 0
        dirs = [0, 1, 0, -1, 0]
        while bfsq:
            y, x = bfsq.popleft()
            for i in range(4):
                ny, nx = y + dirs[i], x + dirs[i+1]
                if ny < 0 or ny >= h or nx < 0 or nx >= w or matrix[ny][nx] != -1:
                    continue
                matrix[ny][nx] = matrix[y][x] + 1
                bfsq.append((ny,nx))
        return matrix
        
if __name__ == "__main__":
    sln = Solution()
    # [[1,0],[2,1]]
    print(sln.highestPeak([[0,1],[0,0]]))
    # [[1,1,0],[0,1,1],[1,2,2]]
    print(sln.highestPeak([[0,0,1],[1,0,0],[0,0,0]]))
