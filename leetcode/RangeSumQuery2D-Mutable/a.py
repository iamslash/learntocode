# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

# 3 0 1 4 2    3  3  4  7  9
# 5 6 3 2 1    5 11 14 16 17
# 1 2 0 1 5    1  3  3  4  9
# 4 1 0 1 7    4  5  5  6 13
# 1 0 3 0 5    1  1  4  4  9

from typing import List

# 128ms 91.05% 16.9MB 32.38%
# partial sum
# sumRegion: O(W)
#    update: O(W)
class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        for line in matrix:
            for x in range(1, len(line)):
                line[x] += line[x-1]
        self.matrix = matrix

    def update(self, row: int, col: int, val: int) -> None:
        w = len(self.matrix[0])
        org = self.matrix[row][col]
        if col > 0:
            org -= self.matrix[row][col-1]
        diff = org - val
        for y in range(col, w):
            self.matrix[row][y] -= diff

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        sum = 0
        for x in range(row1, row2+1):
            sum += self.matrix[x][col2]
            if col1 > 0:
                sum -= self.matrix[x][col1-1]
        return sum
        
if __name__ == "__main__":
    nm = NumMatrix([
        [3, 0, 1, 4, 2],
        [5, 6, 3, 2, 1],
        [1, 2, 0, 1, 5],
        [4, 1, 0, 1, 7],
        [1, 0, 3, 0, 5]])
    # 8
    print(nm.sumRegion(2, 1, 4, 3))
    nm.update(3, 2, 2)
    # 10
    print(nm.sumRegion(2, 1, 4, 3))
    
