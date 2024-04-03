# -*- coding: utf-8 -*-
# Copyright (C) 2024 by iamslash 

from typing import List
import heapq

# 892ms 85.28% 48.1MB 51.59%
# heap
# O(NlgN) O(N)
class Solution:
    def mostFrequentIDs(self, nums: List[int], freq: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        pq = []
        numFreqs = [0] * 100001
        
        for i in range(n):
            num = nums[i]
            numFreqs[num] += freq[i]
            heapq.heappush(pq, (-numFreqs[num], num))

            while pq and numFreqs[pq[0][1]] != -pq[0][0]:
                heapq.heappop(pq)
                
            maxFreq = 0 if not pq else -pq[0][0]
            ans[i] = maxFreq

        return ans
