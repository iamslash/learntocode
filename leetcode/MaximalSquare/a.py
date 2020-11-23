# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# iterative dynamic programming
# O(HW) O(1)
class Solution:
	def maximalSquare(self, M: List[List[str]]) -> int:				
		if len(M) == 0 or len(M[0]) == 0:
			return 0
		h, w, maxLen = len(M), len(M[0]), 0
		C = [[0] * (w + 1) for _ in range(h + 1)]
		for y in range(h):
			for x in range(w):
				if M[y][x] == '1':
					C[y+1][x+1] = min(C[y][x], C[y+1][x], C[y][x+1]) + 1
					maxLen = max(maxLen, C[y+1][x+1])
		return maxLen * maxLen
        