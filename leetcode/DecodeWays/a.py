# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

#  s: 2 7
#         i
# m1: 0 1
# m2: 0 0
# n1: 1 1
# n2: 0 0

# 32ms 62.64% 14MB 88.56%
# iterative programming
# O(N) O(1)
class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == '0':
            return 0        
        n1, n2 = 1, 0
        for i in range(1, len(s)):
            m1, m2 = 0, 0
            if s[i] >= '1' and s[i] <= '9':
                m1 = n1 + n2
            n = int(s[i-1:i+1])
            # print(n)
            if n >= 10 and n <= 26:
                m2 = n1
            n1, n2 = m1, m2
            # print(f'm1:{m1} m2:{m2} n1:{n1} n2:{n2}')
        return n1 + n2
        
if __name__ == "__main__":
    sln = Solution()
    # 1
    print(sln.numDecodings("27"))
    # 2
    print(sln.numDecodings("12"))
    # 3
    print(sln.numDecodings("226"))
    # 0
    print(sln.numDecodings("0"))
    # 1
    print(sln.numDecodings("1"))
