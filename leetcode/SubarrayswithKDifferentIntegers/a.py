# -*- coding: utf-8 -*-
# Copyright (C) 2019 by iamslash 

from typing import List

# 796ms 25.71% 17MB 100.00%
# hash map, sliding window
# O(N) O(N)
from collections import Counter
class Solution:
	def subarraysWithKDistinct(self, A: List[int], K: int) -> int:
		def cntWithMostK(A: List[int], K: int) -> int:
			n, ans, i, j = len(A), 0, 0, 0
			cnt = Counter()
			for j in range(n):
				if cnt[A[j]] == 0:
					K -= 1
				cnt[A[j]] += 1
				while K < 0:
					cnt[A[i]] -= 1
					if cnt[A[i]] == 0:
						K += 1
					i += 1
				ans += j - i + 1
			return ans
		return cntWithMostK(A, K) - cntWithMostK(A, K-1)
	
if __name__ == "__main__":
	A = [1, 2, 1, 2, 3]
	K = 2
	sln = Solution()
	print(sln.subarraysWithKDistinct(A, K))
