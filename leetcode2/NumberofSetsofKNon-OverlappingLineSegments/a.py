# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 28ms 100.00% 14MB 33.33%
# combination
# O(1) O(1)
class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        return math.comb(n + k - 1, k * 2) % (1000000007)
