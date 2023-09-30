# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash

# nums: 3,6 1,5 4,7

# 81ms 69.96% 16.2MB 95.45%
# hash set
# O(N) O(N)
class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        mergedSet = set()
        for s, e in nums:
            mergedSet |= set(range(s, e + 1))
        return len(mergedSet)

# 76ms 88.07% 16.2MB 76.12%
# line sweep
# O(N) O(N)
from collections import Counter
class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        cnt, sum = 0, 0
        evtMap = Counter()
        for beg, end in nums:
            evtMap[beg] += 1
            evtMap[end + 1] -= 1
        for i in range(1, 101):
            sum += evtMap[i]
            if sum > 0:
                cnt += 1
        return cnt
