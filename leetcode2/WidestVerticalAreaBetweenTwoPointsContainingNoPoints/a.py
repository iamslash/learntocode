# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 804ms 100.00% 54.9MB 33.33%
# sort
# O(NlgN) O(N)
class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        A = sorted({x for x, y in points})
        return max([b - a for a, b in zip(A, A[1:])] + [0])
