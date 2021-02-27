# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

#        k: 1
#    bulbs: 1 3 2
# bulb2day: 1 3 2 
# 

class Solution:
    def kEmptySlots(self, bulbs: List[int], k: int) -> int:
        pass
    
if __name__ == "__main__":
    sln = Solution()
    # 2
    print(sln.kEmptySlots([1,3,2], 1))
    # -1
    print(sln.kEmptySlots([1,2,3], 1))
