# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash

from typing import List

# 46ms 51
# hash set
# O(N) O(N)
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        n = len(nums)
        numSet = set()
        for i in range(n - 1, -1, -1):
            if nums[i] <= k:
                numSet.add(nums[i])
            if len(numSet) == k:
                return n - i
        return -1
        
