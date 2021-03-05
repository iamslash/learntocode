# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

# 44ms 85.74% 14.6MB 13.08%
# hash map
# O(N) O(N)
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map, ans = dict(), list()
        for i, a in enumerate(nums):
            b = target - a
            if b in num_map:
                ans += [num_map[b], i]
            num_map[a] = i                
        return ans
        
if __name__ == "__main__":
    sln = Solution()
    # [0, 1]
    print(sln.twoSum([2,7,11,15], 9))
    # [1, 2]
    print(sln.twoSum([3,2,4], 6))
    # [0, 1]
    print(sln.twoSum([3,3], 6))
    # [1, 2]
    print(sln.twoSum([3,2,4], 6))
