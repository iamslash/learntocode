# -*- coding: utf-8 -*-

# 608ms 47.80% 29.6MB 100.00%
# dynamic programming
# O(AB) O(AB)
class Solution:
	def shortestCommonSupersequence(self, a: str, b: str) -> str:
		def lcs(a: str, b: str) -> str:
			m, n = len(a), len(b)
			C = [["" for _ in range(n+1)] for _ in range(m+1)]
			for i in range(m):
				for j in range(n):
					# print("{0} {1}".format(i, j))
					if a[i] == b[j]:
						C[i+1][j+1] = C[i][j] + a[i]
					else:
						C[i+1][j+1] = max(C[i+1][j], C[i][j+1], key=len)
			return C[m][n]
		# print("{0}".format(lcs(a, b)))
		ans, i, j = "", 0, 0
		for c in lcs(a, b):
			while a[i] != c:
				ans += a[i]
				i += 1
			while b[j] != c:
				ans += b[j]
				j += 1
			ans += c
			i, j = i + 1, j + 1
		return ans + a[i:] + b[j:]

if __name__ == "__main__":
	a = "aaaaaaaa"
	b = "aaaaaaaaaa"
  
	sln = Solution()
	print(sln.shortestCommonSupersequence(a, b))
	
