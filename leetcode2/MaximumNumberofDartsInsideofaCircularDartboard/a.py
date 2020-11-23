# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash \

from typing import List

# 424ms 73.33% 14MB 37.78%
class Solution:
	def numPoints(self, P: List[List[int]], r: int) -> int:
		ans = 1
		for (x1, y1), (x2, y2) in itertools.combinations(P, 2):
			d = ((x1 - x2)**2 + (y1 - y2)**2) / 4.0
			if d > r * r:
				continue
			x0 = (x1 + x2) / 2.0 + (y2 - y1) * (r * r - d) ** 0.5 / (d * 4) ** 0.5
			y0 = (y1 + y2) / 2.0 - (x2 - x1) * (r * r - d) ** 0.5 / (d * 4) ** 0.5
			ans = max(ans, sum((x - x0)**2 + (y - y0)**2 <= r * r + 0.00001 for x, y in P))
		return ans
			
if __name__ == "__main__":
	print("Hello World")
