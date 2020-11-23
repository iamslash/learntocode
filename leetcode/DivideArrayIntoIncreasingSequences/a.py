# -*- coding: utf-8 -*-

# 1004ms 22.79% 27.2MB 100.00%
# brute force
# O(N) O(1)
class Solution:
    def canDivideIntoSubsequences(self, A, K) -> bool:
        n, d, l = len(A), 1, 1
        for i in range(1, n):
            if (A[i-1] == A[i]):
                l += 1
            else:
                l = 1
            d = max(d, l)
        return n >= d * K
            
if __name__ == "__main__":
    sln = Solution()
    print(sln.canDivideIntoSubsequences([1, 1, 2, 2], 2))
    print(sln.canDivideIntoSubsequences([1], 2))
