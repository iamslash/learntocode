# -*- coding: utf-8 -*-
# Copyright (C) 2022 by iamslash

# 622ms 31.18% 15.1MB 70.66%
# two pointers
# O(N) O(1)
class Solution:
    def canChange(self, s: str, t: str) -> bool:
        i, j, n = 0, 0, len(s)
        while i < n or j < n:
            while i < n and s[i] == '_':
                i += 1
            while j < n and t[j] == '_':
                j += 1
            if i == n or j == n or s[i] != t[j] or (s[i] == 'L' and i < j) or (s[i] == 'R' and i > j):
                break                
            i += 1
            j += 1
        return i == n and j == n
        
