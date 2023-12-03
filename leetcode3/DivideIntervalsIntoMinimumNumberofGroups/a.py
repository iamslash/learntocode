# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash

from typing import List

# 1475ms 19.78% 59.2MB 22.53%
# sort
# O(NlgN) O(N)
class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        evts = []
        for s, e in intervals:
            evts.append([s, 1])
            evts.append([e + 1, -1])
        ans, cur = 0, 0
        for ts, diff in sorted(evts):
            cur += diff
            ans = max(ans, cur)
        return ans
