# -*- coding: utf-8 -*-
# Copyright (C) 2024 by iamslash 

from typing import List

# 454 52.98% 16.6MB 71.33%
# two pointers, sort
# O(N^3) O(N)
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()  # Sort the list to facilitate two-pointer approach
        ans = set()  # Use a set to avoid duplicate quadruplets
        n = len(nums)
        
        for i in range(n - 3):
            if i > 0 and nums[i] == nums[i - 1]:  # Skip duplicate for nums[i]
                continue
            for j in range(i + 1, n - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:  # Skip duplicate for nums[j]
                    continue
                l, r = j + 1, n - 1
                while l < r:
                    total = nums[i] + nums[j] + nums[l] + nums[r]
                    if total == target:
                        ans.add((nums[i], nums[j], nums[l], nums[r]))
                        l += 1
                        while l < r and nums[l] == nums[l - 1]:  # Skip duplicates for nums[l]
                            l += 1
                        r -= 1
                        while l < r and nums[r] == nums[r + 1]:  # Skip duplicates for nums[r]
                            r -= 1
                    elif total < target:
                        l += 1
                    else:
                        r -= 1
        return [list(quadruplet) for quadruplet in ans]  # Convert to list of lists

