# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash

# 1558ms 26.55% 27MB 48.68%
from sortedcontainers import SortedList
class Solution:
	def continuousSubarrays(self, nums: List[int]) -> int:
		n = len(nums)
		sl = SortedList()
		res = 0
		l = 0
		for r in range(n):
			sl.add(nums[r])
			while l <= r and sl[-1] - sl[0] > 2:
				sl.remove(nums[l])
				l += 1
			res += (r - l +1)
		return res           

# 975ms 59.81% 26.8MB 76.77%
# hash map
# O(N^2) O(N)
class Solution:
    def continuousSubarrays(self, nums):
        n, total, left, cntDict = len(nums), 0, 0, defaultdict(int)
        for right in range(n):
            cntDict[nums[right]] += 1
            while max(cntDict.keys()) - min(cntDict.keys()) > 2:
                cntDict[nums[left]] -= 1
                if cntDict[nums[left]] == 0:
                    del cntDict[nums[left]]
                left += 1
            total += right - left + 1
        return total
