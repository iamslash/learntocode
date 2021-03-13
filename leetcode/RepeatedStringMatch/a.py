# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

# abcdabcdabcd
# cdabcdab

# 108ms 43.74% 14.5MB 34.80%
# brute force
# O(N) O(N)
class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        s   = ""
        cnt = 0
        while len(s) < len(b):
            s   += a
            cnt += 1
        if b in s:
            return cnt
        s += a
        if b in s:
            return cnt + 1
        return -1
        
if __name__ == "__main__":
    sln = Solution()
    # 3
    print(sln.repeatedStringMatch("abcd", "cdabcdab"))
    # 2
    print(sln.repeatedStringMatch("a", "aa"))
    # 1
    print(sln.repeatedStringMatch("a", "a"))
    # -1
    print(sln.repeatedStringMatch("abc", "wxyz"))
