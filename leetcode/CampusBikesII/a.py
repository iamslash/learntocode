# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

from typing import List
import sys

class Solution:
    def assignBikes(self, W: List[List[int]], B: List[List[int]]) -> int:
        def dist(a, b, c, d):
            return abs(a - c) + abs(b - d)
        m, n = len(W), len(B)
        C = [[sys.maxsize] * (1 << n) for _ in range(m+1)]
        C[0][0] = 0
        return min(C[-1])
        for i, worker in enumerate(W):
            for bused in range((1 << n)):
                for j, bike in enumerate(B):
                    _get, _set = B & (1 << j), bused | (1 << j)
                    if not _get:
                        C[i+1][_set] = min(
                            C[i+1][_set],
                            C[i][bused] + dist(*worker, *bike)
                        )
