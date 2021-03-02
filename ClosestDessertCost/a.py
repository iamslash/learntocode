# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

class Solution:
    def closestCost(self, baseCosts: List[int], toppingCosts: List[int], target: int) -> int:
        pass
    
if __name__ == "__main__":
    sln = Solution()
    # 10
    print(sln.closestCost([1,7], [3,4], 10))
    # 17
    print(sln.closestCost([2,3], [4,5,100], 10))
    # 8
    print(sln.closestCost([3,10], [2,5], 9))
    # 10
    print(sln.closestCost([10], [1], 1))
