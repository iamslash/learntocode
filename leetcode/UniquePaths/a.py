# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash

# 1 1 1
# 0 0 0
# 0 0 0

# 32ms 58.06% 14.3MB 20.59%
# iterative dynamic programming
# O(HW) O(HW)
class Solution:
    def uniquePaths(self, h: int, w: int) -> int:
        # C = [[0 for _ in range(w)] for _ in range(h)]
        C = [[0] * w for _ in range(h)]
        # C = [[0] * w] * h
        C[0][0] = 1
        for y in range(0,h):
            for x in range(0,w):
                # print(f'y:{y} x:{x} c:{C[y][x]}')                
                if y > 0:
                    C[y][x] += C[y-1][x]
                if x > 0:
                    C[y][x] += C[y][x-1]
                # print(f'c:{C[y][x]}')
        # print(f'h:{h}, w:{w}, C:{C[h-1][w-1]}')
        return C[h-1][w-1]
        
if __name__ == "__main__":
    sln = Solution()
    # 2
    print(sln.uniquePaths(2, 2))
    # 6
    print(sln.uniquePaths(3, 3))
    # 28
    print(sln.uniquePaths(3, 7))
    # 3
    print(sln.uniquePaths(3, 2))
    # 28
    print(sln.uniquePaths(7, 3))
