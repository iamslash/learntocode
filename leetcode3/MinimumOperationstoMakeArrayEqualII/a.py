# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash

from typing import List

# greedy
# 617ms 48.02% 32.9MB 20.79%
class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        n, up, dn = len(nums1), 0, 0
        if k == 0:
            for i in range(n):
                if nums1[i] != nums2[i]:
                    return -1
            return 0
        for i in range(n):
            diff = abs(nums1[i] - nums2[i])
            if diff % k > 0:
                return -1
            quo = diff // k
            if nums1[i] > nums2[i]:
                up += quo
            elif nums1[i] < nums2[i]:
                dn += quo
        return up if up == dn else -1


# 607ms 70.79% 32.9MB 20.79%
# greedy
# O(N) O(1)
class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        if k == 0:
            return 0 if nums1 == nums2 else -1
        global_diff, cnt, n = 0, 0, len(nums1)
        for i in range(n):
            diff = nums1[i] - nums2[i]
            if diff % k:
                return -1
            global_diff += diff
            cnt += abs(diff // k)
        if global_diff != 0:
            return -1
        return cnt // 2
    
