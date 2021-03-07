# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

# 708ms 10.00% 19.3MB 50.00%
# brute force
# O(N) O(1)
class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        minidx, mindist = -1, 20000
        for i in range(len(points)):
            pt = points[i]
            if x != pt[0] and y != pt[1]:
                continue
            curdist = abs(x-pt[0]) + abs(y-pt[1])
            if (curdist < mindist):
                minidx = i
                mindist = curdist
        return minidx
    
if __name__ == "__main__":
    sln = Solution()
    # 2
    print(sln.nearestValidPoint(3, 4, [[1,2],[3,1],[2,4],[2,3],[4,4]]))
    # 0
    print(sln.nearestValidPoint(3, 4, [[3,4]]))
    # -1
    print(sln.nearestValidPoint(3, 4, [[2,3]]))
