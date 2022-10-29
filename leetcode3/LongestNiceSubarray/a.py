# -*- coding: utf-8 -*-
# Copyright (C) 2022 by iamslash

from typing import List

# 2062ms 25.73% 29.4MB 20.88%
# two pointers, bit manipulation
# O(N) O(1)
class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        ans, bm, i, n = 0, 0, 0, len(nums)
        for j in range(n):
            while bm & nums[j]:
                bm ^= nums[i]
                i += 1
            bm |= nums[j]
            ans = max(ans, j - i + 1)
        return ans
    
