# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

# 416ms 81.37% 14.7MB 67.45%
# dynamic programming
# O(N) O(N)
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 != 0:
            return False
        half = total // 2
        sum_set = set([0])
        for num in nums:
            sum_lst = []
            for i in sum_set:
                if i + num == half:
                    return True
                if i + num < half:
                    sum_lst.append(i + num)
            sum_set.update(sum_lst)
        return False
                
if __name__ == '__main__':
    sln = Solution()
    # True
    print(sln.canPartition([1, 5, 11, 5]))
    # False
    print(sln.canPartition([1, 2, 3, 5]))
