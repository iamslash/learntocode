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


# 58ms 97.22% 16.7MB 59.24% 
# two pointers, sort
# O(N^3) O(N)
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        def findnsum(l, r, target, n, path, rst):
            # Skip unexpected nums
            if r - l + 1 < n or n < 2 or target < nums[l] * n or target > nums[r] * n:
                return
            # base
            if n == 2:
                while l < r:
                    s = nums[l] + nums[r]
                    if s == target:
                        rst.append(path + [nums[l], nums[r]])
                        l += 1
                        while l < r and nums[l] == nums[l - 1]:
                            l += 1
                    elif s < target:
                        l += 1
                    else:
                        r -= 1
                return

            # recursion
            for i in range(l, r + 1):
                if i == l or (i > l and nums[i - 1] != nums[i]):
                    findnsum(i + 1, r, target - nums[i], n - 1, path + [nums[i]], rst)
                    
        nums.sort()
        ans = []
        findnsum(0, len(nums) - 1, target, 4, [], ans)
        return ans
            
