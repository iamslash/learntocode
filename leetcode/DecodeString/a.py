# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 32ms 38.31% 14MB 99.97%
# stack
# O(N) O(N)
class Solution:
    def decodeString(self, s: str) -> str:
        stck, curNum, curStr = [], 0, ''
        for c in s:
            if c == '[':
                stck.append(curStr)
                stck.append(curNum)
                curNum, curStr = 0, ''
            elif c == ']':
                num = stck.pop()
                prvStr = stck.pop()
                curStr = prvStr + num * curStr
            elif c.isdigit():
                curNum = curNum * 10 + int(c)
            else:
                curStr += c            
        return curStr
    
if __name__ == "__main__":
    sln = Solution()
    print(sln.decodeString('3[a]2[bc]'))
    print(sln.decodeString('3[a2[c]]'))
    print(sln.decodeString('2[abc]3[cd]ef'))
    print(sln.decodeString('abc3[cd]xyz'))
