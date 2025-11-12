# -*- coding: utf-8 -*-
# Copyright (C) 2025 by iamslash

from typing import List

# 0ms 100.00% 18.05MB 10.70%
# back and forth
# O(N) O(1)
class Solution:
    def maxDistance(self, words: List[str]) -> int:
        n = len(words)
        max_dist = 0

        if n == 1:
            return 0

        if words[0] != words[n-1]:
            return n

        for i in range(n - 1):
            if words[n-1] != words[i]:
                max_dist = max(max_dist, n - i)
                break

        for i in range(n - 1, 0, -1):
            if words[0] != words[i]:
                max_dist = max(max_dist, i + 1)
                break

        return max_dist        

def main():
    pass

if __name__ == "__main__":
    main()
