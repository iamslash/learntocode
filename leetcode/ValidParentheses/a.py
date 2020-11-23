# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 28ms 80.30% 14MB 100.00%
# stack
# O(N) O(N)
class Solution:
    def isValid(self, s: str) -> bool:
        d = {'(': ')', '{': '}', '[': ']'}
        stck = []
        for c in s:
            if c in d:
                stck.append(c)
            elif len(stck) == 0 or c != d[stck.pop()]:
                return False
        return len(stck) == 0

if __name__ == '__main__':
    sln = Solution()

    print(sln.isValid("()"))     # True
    print(sln.isValid("()[]{}")) # True
    print(sln.isValid("(]"))     # False
    print(sln.isValid("(())"))   # True
    print(sln.isValid("((]}"))   # False
    
