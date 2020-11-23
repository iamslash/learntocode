import sys

# 4816ms 30.03% 14.2MB 57.39%
# iterative dynamic programming
# O(N^2) O(N)
class Solution:
    def numSquares(self, n: int) -> int:
        C = [sys.maxsize] * (n+1)
        C[0] = 0
        for i in range(1, n+1):
            j = 1
            while j*j <= i:
                C[i] = min(C[i], C[i - j*j] + 1)
                j += 1
        return C[n]

