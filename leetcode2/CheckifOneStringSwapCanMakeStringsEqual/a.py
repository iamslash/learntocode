# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash 

# 32ms 100.00% 14.2MB 100.00%
# brute force
# O(N) O(1)
class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        diff = [[a, b] for a, b in zip(s1, s2) if a != b]
        if not diff:
            return True
        if len(diff) == 2 and diff[0][::-1] == diff[1]:
            return True
        return False
        
if __name__ == "__main__":
    sln = Solution()
    # True
    print(sln.areAlmostEqual("bank", "kanb"))
    # False
    print(sln.areAlmostEqual("attack", "defend"))
    # True
    print(sln.areAlmostEqual("kelb", "kelb"))
    # False
    print(sln.areAlmostEqual("abcd", "dcba"))
