# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 16ms 100.00% 14MB 100.00%
# iterative dynamic programming
# O(N) O(1)
class Solution:
    def countVowelStrings(self, n: int) -> int:
        a, e, i, o, u = 1, 1, 1, 1, 1
        for _ in range(n-1):
            u = u
            o = o + u
            i = i + o
            e = e + i
            a = a + e
        return a + e + i + o + u
