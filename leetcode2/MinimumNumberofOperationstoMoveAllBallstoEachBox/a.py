# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

#          i
# boxes: 0 0 1 0 1  1
#   ops: 0 0
#   cnt: 0 0
#   ans: 0 0

# 92ms 100.00% 14.5MB 100.00%
# back and forth
# O(N) O(N)
class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n, ops, cnt = len(boxes), 0, 0
        ans = [0]*n
        for i in range(0, n):
            ans[i] = ops
            cnt += 1 if boxes[i] == '1' else 0
            ops += cnt
        ops, cnt = 0, 0
        for i in range(n-1, -1, -1):
            ans[i] += ops
            cnt += 1 if boxes[i] == '1' else 0
            ops += cnt
        return ans
        
if __name__ == "__main__":
    sln = Solution()
    # [1,1,3]
    print(sln.minOperations("110"))
    # [11,8,5,4,3,4]
    print(sln.minOperations("001011"))
