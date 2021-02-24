# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

#                 g
# groups: 1,-1,-1 3,-2,0
#                               i 
#   nums: 1 -1 0 1 -1 -1 3 -2 0
#                               j

# 80ms 50.00% 14.6MB 50.00%
# brute force
# O(G^2N) O(1)
class Solution:
    def canChoose(self, groups: List[List[int]], nums: List[int]) -> bool:
        i, n = 0, len(nums)
        for group in groups:
            for j in range(i, n):
                if nums[j:j+len(group)] == group:
                    i = j + len(group)
                    break
            else:
                return False
        return True
        
if __name__ == "__main__":
    sln = Solution()
    # true
    print(sln.canChoose([[1,-1,-1],[3,-2,0]], [1,-1,0,1,-1,-1,3,-2,0]))
    # false
    print(sln.canChoose([[10,-2],[1,2,3,4]], [1,2,3,4,10,-2]))
    # false
    print(sln.canChoose([[1,2,3],[3,4]], [7,7,1,2,3,4,7,7]))
          
    
