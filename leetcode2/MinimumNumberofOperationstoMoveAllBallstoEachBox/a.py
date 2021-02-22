# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

#          i
# boxes: 0 0 1 0 1  1
#   ops: 0
#   cnt: 0
#   ans: 0 0

# partial sum
class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        pass
        
if __name__ == "__main__":
    sln = Solution()
    # [1,1,3]
    print(sln.minOperations("110"))
    # [11,8,5,4,3,4]
    print(sln.minOperations("001011"))
