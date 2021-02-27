# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List
from collections import Counter

# 840ms 57.69% 20.1MB 24.44%
# two pointers
# O(N) O(N)
class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        i, j, n = 0, 0, len(tree)
        cntmap = Counter()
        for j in range(n):
            cntmap[tree[j]] += 1
            if len(cntmap) > 2:
                cntmap[tree[i]] -= 1
                if cntmap[tree[i]] == 0:
                    cntmap.pop(tree[i])
                i += 1
        return j - i + 1
        
if __name__ == "__main__":
    sln = Solution()
    # 3
    print(sln.totalFruit([1,2,1]))
    # 3
    print(sln.totalFruit([0,1,2,2]))
    # 4
    print(sln.totalFruit([1,2,3,2,2]))
    # 5
    print(sln.totalFruit([3,3,3,1,2,1,1,2,3,3,4]))
