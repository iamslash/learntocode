# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

# 1332ms 100.00% 20.4MB 10.00%
# sort
# O(NlgN) O(N)
class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        sum1, sum2 = sum(nums1), sum(nums2)
        if sum1 > sum2:
            sum1, sum2 = sum2, sum1
            nums1, nums2 = nums2, nums1
        ans, diff = 0, sum2 - sum1
        if diff == 0:
            return 0
        removes = [6 - num for num in nums1]
        removes += [num - 1 for num in nums2]
        removes.sort(reverse=True)
        for remove in removes:
            ans += 1
            diff -= remove
            if diff <= 0:
                return ans
        return -1
    
if __name__ == "__main__":
    sln = Solution()
    # 3
    print(sln.minOperations([1,2,3,4,5,6], [1,1,2,2,2,2]))
    # -1
    print(sln.minOperations([1,1,1,1,1,1,1], [6]))
