# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

#    i
# s: Y a z a A a y
#                  j

# 156ms 25.00% 14.4MB 25.00%
# brute force
# O(N^3) O(1)
class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        ans = ''
        for i in range(len(s)):
            for j in range(i+1, len(s)+1):
                if all(s[k].swapcase() in s[i:j] for k in range(i, j)):
                    ans = max(ans, s[i:j], key=len)
        return ans
    
if __name__ == "__main__":
    sln = Solution()
    # aAa
    print(sln.longestNiceSubstring('YazaAay'))
    # Bb
    print(sln.longestNiceSubstring('Bb'))
    # ''
    print(sln.longestNiceSubstring('c'))
    # dD
    print(sln.longestNiceSubstring('dDzeE'))
