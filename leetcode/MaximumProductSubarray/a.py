# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

from typing import List

# 60ms 37.32% 14.4MB 24.66%
# kadane's algorithm
# O(N) O(1)
class Solution:
    def maxProduct(self, A: List[int]) -> int:
        last_min = A[0]
        last_max = A[0]
        glb_max = A[0]
        for i in range(1, len(A)):
            t_min = min(last_min * A[i], last_max * A[i])
            t_max = max(last_min * A[i], last_max * A[i])
            last_min = min(A[i], t_min)
            last_max = max(A[i], t_max)
            glb_max = max(glb_max, last_max)
        return glb_max

# 48ms 94.52% 15MB 23.66%
# prefix sum
# O(N) O(N)
class Solution:
    def maxProduct(self, A: List[int]) -> int:
        # reversed from A
        R = A[::-1]
        for i in range(1, len(A)):
            A[i] *= A[i-1] or 1
            R[i] *= R[i-1] or 1
        return max(A + R)
