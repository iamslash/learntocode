# -*- coding: utf-8 -*-
# Copyright (C) 2019 by iamslash 

# 64ms 67.02% 14.5MB 100.00%
# dynamic programming
# O(N^2) O(N^2)
class Solution:
	def numPermsDISequence(self, s: str) -> int:
		MOD = 10**9+7 # 1000000007
		n = len(s)
		C = [[0 for j in range(n+1)] for i in range(n+1)]
		C[0] = [1 for j in range(n+1)]
		for i in range(n):
			if s[i] == "I":
				k = 0
				for j in range(n-i):
					C[i+1][j] = (k + C[i][j]) % MOD
					k = C[i+1][j]
			else:
				k = 0
				for j in reversed(range(n-i)):
					C[i+1][j] = (k + C[i][j+1]) % MOD
					k = C[i+1][j]
		return C[n][0]

if __name__ == "__main__":
	sln = Solution()
	print(sln.numPermsDISequence("DID"))
