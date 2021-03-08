# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List
from math import ceil

# 772ms 100.00% 27.3MB 100.00%
# math
# O(N) O(2)
class Solution:
    def minElements(self, nums: List[int], limit: int, goal: int) -> int:
        diff = goal - sum(nums)
        return ceil((abs(diff)) / limit)
    
if __name__ == "__main__":
    sln = Solution()
    # 2
    print(sln.minElements([1,-1,1],3,-4))
    # 1
    print(sln.minElements([1,-1,9,1],100,0))
    # 771843705
    print(sln.minElements([-1,0,1,1,1],1,771843707))

