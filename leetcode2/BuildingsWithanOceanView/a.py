# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

# heights: 4 2 3 1
#          i
#          1 3 2 4
#          0
#    maxH: 0
#     ans: 3

from typing import List

# 704ms 100.00% 31.1MB 100.00%
# greedy algorithm
# O(N) O(N)
class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        ans = []
        maxHeight, n = 0, len(heights)
        for i, v in enumerate(heights[::-1]):
            if v > maxHeight:
                ans.append(n-1-i)
                maxHeight = v
        return ans[::-1]
                
if __name__ == "__main__":
    sln = Solution()
    # [0,2,3]
    print(sln.findBuildings([4,2,3,1]))
    # [0,1,2,3]
    print(sln.findBuildings([4,3,2,1]))
    # [3]
    print(sln.findBuildings([1,3,2,4]))
