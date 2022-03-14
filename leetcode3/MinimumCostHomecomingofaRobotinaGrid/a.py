# -*- coding: utf-8 -*-
# Copyright (C) 2022 by iamslash

# 1676ms 76.98% 28.9MB 50.86%
# matrix
# O(N) O(1)
class Solution:
    def minCost(self, startPos: List[int], homePos: List[int], rowCosts: List[int], colCosts: List[int]) -> int:
        cost, y, x, z, w = 0, startPos[0], startPos[1], homePos[0], homePos[1]
        while y != z:
            y += int((z - y) / abs(z - y))
            cost += rowCosts[y]
        while x != w:
            x += int((w - x) / abs(w - x))
            cost += colCosts[x]
        return cost
