# -*- coding: utf-8 -*-
# Copyright (C) 2019 by iamslash 

# 76ms 26.38% 13.8MB 100.00%
# math
# O(NlgN) O(N)
class Solution:
	def maximumNumberOfOnes(
			self, w: int, h: int,
			sidelen: int, maxone: int) -> int:
		rec = []
		for i in range(sidelen):
			for j in range(sidelen):
				r = (h - i - 1) // sidelen + 1
				c = (w - j - 1) // sidelen + 1
				rec.append(r * c)
		rec.sort(reverse=True)
		ans = 0
		for i in range(maxone):
			ans += rec[i]
		return ans
	
if __name__ == "__main__":
  pass
