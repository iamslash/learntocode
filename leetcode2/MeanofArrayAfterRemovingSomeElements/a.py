# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 56ms 20.00% 14.4MB 100.00%
# sort
# O(NlgN) O(1)
class Solution:
    def trimMean(self, A: List[int]) -> float:
        A = sorted(A)
        n, sum = len(A), 0
        m, p = n * 0.9, n * 0.05
        for i in range(p, m + p):
            sum += A[i]
        return sum / m
