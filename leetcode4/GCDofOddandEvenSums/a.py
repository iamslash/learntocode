# -*- coding: utf-8 -*-
# Copyright (C) 2025 by iamslash 

# 0ms 100.00%
# math
# O(1) O(1)
class Solution:
    def gcd(self, a: int, b: int) -> int:
        # base
        if b == 0:
            return a        
        # recursion
        return gcd(b, a % b)
    
    def gcdOfOddEvenSums(self, n: int) -> int:

        nn = n + n
        sum = nn * (nn + 1) // 2
        sum_odd = sum - n
        sum_evn = sum_odd + n

        return gcd(sum_evn, sum_odd)
