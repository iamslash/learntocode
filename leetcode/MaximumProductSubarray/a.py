# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List
import sys

# 60ms 38.08% 14.2MB 95.93%
# iterative dynamic programming
# O(N) O(1)
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        glb_max, loc_max, loc_min = nums[0], nums[0], nums[0]
        for num in nums[1:]:
            tmp_max = max(loc_min * num, loc_max * num)
            tmp_min = min(loc_min * num, loc_max * num)
            loc_max = max(tmp_max, num)
            loc_min = min(tmp_min, num)
            glb_max = max(glb_max, loc_max)
        return glb_max
                          
if __name__ == "__main__":
    sln = Solution()
    # 6
    print(sln.maxProduct([2, 3, -2, 4]))
    # 0
    print(sln.maxProduct([-2, 0, -1]))
