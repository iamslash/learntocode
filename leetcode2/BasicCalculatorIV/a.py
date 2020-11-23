# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

from typing import List
import collections
import re

class Solution:
	def basicCalculatorIV(self, expr: str, keys: List[str], vals: List[int]) -> List[str]:
		class Context(collections.Counter):
			def __add__(self, other):
				self.update(other)
				return self
			def __sub__(self, other):
				self.subtract(other)
				return self
			def __mul__(self, other):
				product = Context()
				for x in self:
					for y in other:
						xy = tuple(sorted(x + y))
						product[xy] += self[x] * other[y]
				return product
		envs = dict(zip(keys, vals))
		def env(s):
			s = str(envs.get(s, s))
			if s.isalpha():
				return Context({(s,): 1})
			return Context({(): int(s)})
		ctx = eval(re.sub('(\w+)', r'env("\1")', expr))
		# env("e") + env("8") - env("a") + env("5")
		# Context({(): 14, ('a',): -1})
		ans = []
		for x in sorted(ctx, key = lambda x: (-len(x), x)):
			if ctx[x]:
				ans.append('*'.join((str(ctx[x]),) + x))
		return ans
# 
	
if __name__ == "__main__":
	sln = Solution()
	print(sln.basicCalculatorIV("e + 8 - a + 5", ["e"], [1]))
