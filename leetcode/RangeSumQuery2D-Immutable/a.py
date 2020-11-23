# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 1 1 1 1
# 1 1 1 1
# 1 1 1 1
# 1 1 1 1

# 1 2  3  4
# 2 4  6  8
# 3 6  9 12
# 4 8 12 16
from typing import List

# 112ms 59.84% 17MB 6.24%
# grid sum
# O(HW) O(1)
class NumMatrix:
    def __init__(self, M: List[List[int]]):
        self.ps = M
        for y in range(len(M)):
            for x in range(len(M[0])):
                self.ps[y][x] += self.ps[y-1][x] if y > 0 else 0
                self.ps[y][x] += self.ps[y][x-1] if x > 0 else 0
                self.ps[y][x] -= self.ps[y-1][x-1] if y > 0 and x > 0 else 0
    def sumRegion(self, y1: int, x1: int, y2: int, x2: int) -> int:
        ans  = self.ps[y2][x2]
        ans -= self.ps[y1-1][x2] if y1 > 0 else 0
        ans -= self.ps[y2][x1-1] if x1 > 0 else 0
        ans += self.ps[y1-1][x1-1] if y1 > 0 and x1 > 0 else 0
        return ans

if __name__ == "__main__":
    main()
