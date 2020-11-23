# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 72ms 79,53% 14.5MB 21.14%
# iterative dynamic programming
# O(N) O(N)
class Solution:
    def new21Game(self, N: int, K: int, W: int) -> float:
        if K == 0 or N >= K + W:
            return 1.0
        C = [1.0] + [0.0] * N
        psum = 1.0
        for i in range(1, N+1):
            C[i] = psum / W
            if i < K:
                psum += C[i]
            if i - W >= 0:
                psum -= C[i-W]
        return sum(C[K:])
                
if __name__ == "__main__":
    sln = Solution()
    print(sln.new21Game(10, 1, 10)) # 1.00000
    print(sln.new21Game(6, 1, 10)) # 0.60000
    print(sln.new21Game(21, 17, 10)) # 0.73278
