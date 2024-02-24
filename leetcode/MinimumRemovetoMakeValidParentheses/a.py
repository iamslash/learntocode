# -*- coding: utf-8 -*-
# Copyright (C) 2024 by iamslash 

# 80ms 56.92% 18.7MB 47.17%
# stack
# O(N) O(N)
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        lefts = []
        rights = set()

        for i, c in enumerate(s):
            if c == '(':
                lefts.append(i)
            elif c == ')':
                if lefts:
                    lefts.pop()
                else:
                    rights.add(i)

        rights = rights.union(set(lefts))
        return ''.join(c for i, c in enumerate(s) if i not in rights)

# 64ms 86.12% 18.2MB 81.38%
# stck
# O(N) O(N)
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stck = []
        ans = list(s)

        for i in range(len(s)):
            if ans[i] == '(':
                stck.append(i)
            elif ans[i] == ')':
                if stck:
                    stck.pop()
                else:
                    ans[i] = ''

        for i in stck:
            ans[i] = ''

        return ''.join(ans)
