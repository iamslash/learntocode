# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash 

# 32ms 100.00% 14.3MB 100.00%
# split
# O(N) O(1)
class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        return len([seg for seg in s.split('0') if len(seg) > 0]) <= 1
    
if __name__ == "__main__":
    sln = Solution()
    # False
    print(sln.checkOnesSegment("1001"))
    # True
    print(sln.checkOnesSegment("110"))
    # True
    print(sln.checkOnesSegment("1"))
    # True
    print(sln.checkOnesSegment("10"))

