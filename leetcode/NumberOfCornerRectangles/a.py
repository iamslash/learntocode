# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash

from typing import List

# 3484ms 12.24% 14.8MB 97.28%
# combination
# O(H^2W) O(1)
class Solution:
    def countCornerRectangles(self, G: List[List[int]]) -> int:
        ans, h, w = 0, len(G), len(G[0])
        for i in range(h-1):
            for j in range(i+1, h):
                cnt = 0
                for x in range(w):
                    if G[i][x] == 1 and G[j][x] == 1:
                        cnt += 1
                if cnt > 0:
                    ans += cnt * (cnt - 1) // 2
        return ans

if __name__ == '__main__':
    sln = Solution()
    print(sln.countCornerRectangles([[1,0,0,1,0],[0,0,1,0,1],[0,0,0,1,0],[1,0,1,0,1]]))
