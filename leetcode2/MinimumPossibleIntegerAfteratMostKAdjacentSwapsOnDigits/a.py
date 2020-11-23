# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 316ms 85.64% 484.7MB 6.08%
class Solution:
	def minInteger(self, s: str, k: int) -> str:
		# base
		if k <= 0:
			return s
		n = len(s)
		if k >= n*(n+1)/2:
			return "".join(sorted(list(s)))
		for i in range(10):
			idx = s.find(str(i))
			if 0 <= idx <= k:
				return str(s[idx]) + self.minInteger(s[0:idx] + s[idx+1:], k-idx)
				