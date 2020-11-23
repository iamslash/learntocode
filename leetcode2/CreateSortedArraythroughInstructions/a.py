# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

from typing import List

# 5252ms 80.50% 28MB 5.03%
# fenwick tree
# O(NlgN) O(N)
class Solution:
    def createSortedArray(self, I: List[int]) -> int:
        max_val, mod = max(I), 1000000007
        data = [0] * (max_val + 1)
        def lsb(x):
            return x & -x
        def add(x):
            while x <= max_val:
                data[x] += 1
                x += lsb(x)
        def sum(x):
            ans = 0
            while x > 0:
                ans += data[x]
                x -= lsb(x)
            return ans
        ans = 0
        for i, a in enumerate(I):
            ans = (ans + min(sum(a-1), i - sum(a))) % mod
            add(a)
        return ans
    
if __name__ == "__main__":
    sln = Solution()
    print(sln.createSortedArray([1,5,6,2])) # 1
    print(sln.createSortedArray([1,2,3,6,5,4])) # 3
    print(sln.createSortedArray([1,3,3,3,2,4,2,1,2])) # 4
