# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash

from typing import List
import heapq

# 900ms 87.33% 26.3MB 75.11%
# priority queue
# O(NlgN) O(N)
class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        pq = []
        for a in nums:
            heapq.heappush(pq, -a * 2 if a % 2 > 0 else -a)
        ans = float('inf')
        minNum = -max(pq)
        while True:
            # print(pq)
            # print(minNum)          
            num = -heapq.heappop(pq)
            ans = min(ans, num - minNum)
            if num % 2 > 0:
                break
            num //= 2
            minNum = min(minNum, num)
            heapq.heappush(pq, -num)
        return ans
                
if __name__ == "__main__":
    sln = Solution()
    # 1
    print(sln.minimumDeviation([1,2,3,4]))
    # 3
    print(sln.minimumDeviation([4,1,5,20,3]))
    # 3
    print(sln.minimumDeviation([2,10,8]))
