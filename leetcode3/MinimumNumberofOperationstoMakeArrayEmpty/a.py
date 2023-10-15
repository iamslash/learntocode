# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash

from typing import List

# 623ms 33.96% 31.1MB 27.47%
# hash map
# O(N) O(N)
from collections import defaultdict
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        cnt_map = defaultdict(int)
        for num in nums:
            cnt_map[num] += 1
        ans = 0
        for num in cnt_map.keys():
            cnt = cnt_map[num]
            if cnt == 1:
                return -1
            ans += (cnt + 2) // 3
        return ans
    
