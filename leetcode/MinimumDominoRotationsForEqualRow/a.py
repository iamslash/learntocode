# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

# A: 2 1 2 4 2 2
# B: 5 2 6 2 3 2
#
# 

# A: 3 5 1 2 3
# B: 3 6 3 3 4
# 

# 1056ms 95.26% 15.5MB 18.06%
# brute force
# O(N) O(1)
class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        for x in [A[0], B[0]]:
            if all(x in d for d in zip(A, B)):
                return len(A) - max(A.count(x), B.count(x))
        return -1
    
if __name__ == "__main__":
    sln = Solution()
    # 2
    print(sln.minDominoRotations([2,1,2,4,2,2], [5,2,6,2,3,2]))
    # -1
    print(sln.minDominoRotations([3,5,1,2,3], [3,6,3,3,4]))
