# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

# 860ms 100.00% 50MB 100.00%
# set
# O(N) O(1)
class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        center_set = set()
        for edge in edges:
            center_set = set(edge) if not center_set else center_set.intersection(set(edge))
        return center_set.pop()

# 776ms 100.00% 50.1MB 100.00%
# set
# O(N) O(1)
class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        return (set(edges[0]) & set(edges[1])).pop()

    
if __name__ == "__main__":
    sln = Solution()
    # 2
    print(sln.findCenter([[1,2],[2,3],[4,2]]))
    # 1
    print(sln.findCenter([[1,2],[5,1],[1,3],[1,4]]))
