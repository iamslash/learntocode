# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

from typing import List
from bisect import bisect_left

# 72ms 84.79% 14.7MB 32.84%
# binary search
# O(NlgN) O(N)
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        lis = [0] * len(nums)
        ans = 0
        for i in range(len(nums)):
            j = bisect_left(lis, nums[i], hi = ans)
            lis[j] = nums[i]
            ans = max(ans, j+1)
        return ans

if __name__ == "__main__":
    sln = Solution()
    # 4
    print(sln.lengthOfLIS([10,9,2,5,3,7,101,18]))
    # 4
    print(sln.lengthOfLIS([0,1,0,3,2,3]))
    # 4
    print(sln.lengthOfLIS([7,7,7,7,7,7,7]))
