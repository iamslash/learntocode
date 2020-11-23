# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

from typing import List
from collections import deque

# 1572ms 19.96% 29.7MB 86.63%
# sliding window, deque
# O(N) O(N)
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        deq = deque()
        ans = [0] * (len(nums)-k+1)
        for i in range(len(nums)):
            # descending order
            while len(deq) > 0 and nums[deq[-1]] < nums[i]:
                deq.pop()
            deq.append(i)
            # push max value
            if len(deq) > 0 and i >= k - 1:
                ans[i-k+1] = nums[deq[0]]
            # remove out of index
            if len(deq) > 0 and deq[0] <= i - k + 1:
                deq.popleft()
        return ans
        
if __name__ == "__main__":
    sln = Solution()
    print(sln.maxSlidingWindow([1,3,-1,-3,5,3,6,7], 3))
    print(sln.maxSlidingWindow([4,3,11], 3))
    print(sln.maxSlidingWindow([1,3,1,2,0,5], 3)) # [3,3,2,5]
