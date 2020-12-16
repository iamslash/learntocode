# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash

from typing import List

# 228ms 27.37% 14.5MB 27.02%
# itertaive dynamic programming
# O(N^2) O(N^2)
class Solution:
    def maxHeight(self, A: List[List[int]]) -> int:
        A = [[0, 0, 0]] + sorted(map(sorted, A))
        C = [0] * len(A)
        for j in range(1, len(A)):
            for i in range(j):
                if all(A[i][k] <= A[j][k] for k in range(3)):
                    C[j] = max(C[j], C[i] + A[j][2])
        return max(C)
        
if __name__ == "__main__":
    sln = Solution()
    # 190
    print(sln.maxHeight([[50,45,20],[95,37,53],[45,23,12]]))
    # 76
    print(sln.maxHeight([[38,25,45],[76,35,3]]))
    # 102
    print(sln.maxHeight([[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]))
