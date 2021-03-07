# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash 

from functools import lru_cache

# 1132ms 50.005 14.1MB 100.00%
# backtracking
# O(2^N) O(N)
class Solution:
    @lru_cache(maxsize=32)
    def checkPowersOfThree(self, n: int, i: int = 0) -> bool:
        # base
        if n == 0:
            return True
        if 3**i > n:
            return False
        # recursion
        if self.checkPowersOfThree(n-3**i, i+1):
            return True
        return self.checkPowersOfThree(n, i+1)

# 32ms 100.00% 14.1MB 100.00%
# math
class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        for i in range(20, -1, -1):
            if n >= 3**i:
                n -= 3**i
        return n == 0
    
if __name__ == "__main__":
    sln = Solution()
    # True
    print(sln.checkPowersOfThree(12))
    # True
    print(sln.checkPowersOfThree(91))
    # False
    print(sln.checkPowersOfThree(21))
