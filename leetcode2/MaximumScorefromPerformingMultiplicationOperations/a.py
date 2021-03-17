# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List
#   l
# 0 1 2 3 4
#       r
#     i 
# a b c d

# 9376ms 33.33% 176.1MB 66.67%
# dynamic programming
# O(M^2) O(M^2)
class Solution:
    def maximumScore(self, nums: List[int], mults: List[int]) -> int:
        C = [[None for x in range(len(mults))] for y in range(len(mults))]
        def dfs(l: int, i: int) -> int:
            # print(f'{l}, {i}')
            # base
            if i >= len(mults):
                return 0;
            # memo
            if not C[l][i]:
                return C[l][i]
            # recursion
            r = len(nums) - 1 - (i - l)
            C[l][i] = max(nums[l] * mults[i] + dfs(l + 1, i + 1), nums[r] * mults[i] + dfs(l, i + 1))
            return C[l][i]                
        return dfs(0, 0)
        
if __name__ == "__main__":
    sln = Solution()
    # 14
    print(sln.maximumScore([1,2,3], [3,2,1]))
    # 102
    print(sln.maximumScore([-5,-3,-3,-2,7,1], [-10,-5,3,4,6]))
    
