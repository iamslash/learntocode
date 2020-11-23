# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# sort, hash map
# O(NlgN) O(N)
class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        cntMap = collections.Counter(nums)
        ans = sorted(nums, key = lambda a: (cntMap[a],-a))
        return ans
