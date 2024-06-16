# -*- coding: utf-8 -*-
# Copyright (C) 2024 by iamslash

from typing import List

# 46ms 100.00% 16.5MB 100.00%
# hash map
# O(N) O(N)
class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        cnt = 0
        ts_cnt_map = {}

        for hr in hours:
            hr %= 24
            cnt += ts_cnt_map.get((24 - hr) % 24, 0)
            ts_cnt_map[hr] = ts_cnt_map.get(hr, 0) + 1

        return cnt
        
