# -*- coding: utf-8 -*-
# Copyright (C) 2022 by iamslash 

# 53ms 30.92% 13.8MB 98.51%
# stack
# O(N) O(1)
class Solution:
    def isValid(self, s: str) -> bool:
        dict = {')': '(', '}': '{', ']': '['}
        stck = []
        for c in s:
            if c == ')' or c == '}' or c == ']':
                if len(stck) == 0 or stck[-1] != dict[c]:
                    return False
                stck.pop()
            else:
                stck.append(c)
        return len(stck) == 0

def main():
    pass

if __name__ == "__main__":
    main()
