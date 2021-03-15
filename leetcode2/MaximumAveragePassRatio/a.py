# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List
import heapq

# 2/3  4/5  32/40
# 4/6  6/8  30/40

# 2/3  4/5
# 1/3  3/5

# 1/2  3/4  21/28
# 3/5  5/7  20/28

# 1/7  3/9  30/90
# 5/8  7/10 63/90

# 2836ms 100.00% 64.2MB 100.00%
# priority queue, heap
# O(NlgN) O(N)
class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        def profit(a, b):
            return (a+1)/(b+1) - a/b
        maxheap = []
        for a, b in classes:
            a, b = a * 1.0, b * 1.0
            maxheap.append((-profit(a,b), a, b))
        heapq.heapify(maxheap)
        for _ in range(extraStudents):
            c, a, b = heapq.heappop(maxheap)
            heapq.heappush(maxheap, (-profit(a+1,b+1), a+1,b+1))
        return sum(a/b for c, a, b in maxheap)/len(maxheap)
    
if __name__ == "__main__":
    sln = Solution()
    # 0.7833
    print(sln.maxAverageRatio([[1,2],[3,5],[2,2]], 2))
    # 0.53485
    print(sln.maxAverageRatio([[2,4],[3,9],[4,5],[2,10]], 4))
