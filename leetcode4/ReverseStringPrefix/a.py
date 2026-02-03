# -*- coding: utf-8 -*-
# Copyright (C) 2026 by iamslash

# 0ms 100.00% 19.32MB 16.39%
# linear traversal
# O(N) O(N)
class Solution:
    def reversePrefix(self, s: str, k: int) -> str:
        s = list(s)
        h = k // 2

        for i in range(h):
            s[i], s[k - i - 1] = s[k - i - 1], s[i]

        return ''.join(s)

# 0ms 100.00% 19.38MB 16.39%
# linear traversal
# O(N) O(N)
class Solution:
    def reversePrefix(self, s: str, k: int) -> str:
        return s[:k][::-1] + s[k:]
    
def main():
    pass

if __name__ == "__main__":
    main()
