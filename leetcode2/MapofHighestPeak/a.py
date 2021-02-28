# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

# 0 1  1 0
# 0 0  2 1

class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        pass
        
if __name__ == "__main__":
    sln = Solution()
    # [[1,0],[2,1]]
    print(sln.highestPeak([[0,1],[0,0]]))
    # [[1,1,0],[0,1,1],[1,2,2]]
    print(sln.highestPeak([[0,0,1],[1,0,0],[0,0,0]]))
