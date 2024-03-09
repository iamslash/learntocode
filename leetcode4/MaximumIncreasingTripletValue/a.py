# -*- coding: utf-8 -*-
# Copyright (C) 2024 by iamslash 

from typing import List
import bisect

# 2671ms 100.00% 31.8MB 100.00%
# O(NlgN) O(N)
class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        right_max_num = [0] * (n + 1)

        for i in range(n - 1, -1, -1):
            right_max_num[i] = max(right_max_num[i + 1], nums[i])

        ans = 0
        num_list = []
        bisect.insort(num_list, nums[0])

        for j in range(1, n - 1):
            # Binary search to find the largest element
            # smaller than nums[j] in num_list
            i_idx = bisect.bisect_left(num_list, nums[j])
            num_i = num_list[i_idx - 1] if i_idx > 0 else None
            
            num_k = right_max_num[j + 1]
            if num_i is not None and num_k > nums[j]:
                ans = max(ans, num_i - nums[j] + num_k)
            bisect.insort(num_list, nums[j])

        return ans
