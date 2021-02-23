# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

# greedy algorithm
# O(N) O(N)
class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        ans = []
        maxHeight = 0
        for i, v in heights[::-1]:
            if v > maxHeight:
                ans.append(i)
        return ans[::-1]                
                
if __name__ == "__main__":
    sln = Solution()
    print(sln.findBuildings([4,3,2,1]))
