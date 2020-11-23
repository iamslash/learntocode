# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 112ms 33.05% 14.8MB 65.25%
# dynamic programming
# O(HW) O(HW)
class Solution:
	def calculateMinimumHP(self, G: List[List[int]]) -> int:
		h, w = len(G), len(G[0])
		C = [[float("inf")] * (w + 1) for _ in range(h + 1)]
		C[h][w-1], C[h-1][w] = 1, 1
		for y in range(h-1, -1, -1):
			for x in range(w-1, -1, -1):
				hp = min(C[y+1][x], C[y][x+1]) - G[y][x]
				if hp <= 0:
					hp = 1
				C[y][x] = hp
		return C[0][0]
