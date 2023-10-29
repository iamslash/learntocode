# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash

from collections import defaultdict
from functools import cache

# 686ms 80.12% 29.1MB 56.78%
# recursive dynamic programming
# diffcult
class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        div = defaultdict(lambda: [1])
        n = len(s)
        for d in range(2, n):
            for v in range(d + d, n + 1, d):
                div[v].append(d)

        def change(i, j):
            return min(semi(i, j, d) for d in div[j - i])

        @cache
        def semi(i, j, d):
            if i >= j:
                return 0
            return semi(i + d, j - d, d) + sum(s[i + ii] != s[j - d + ii] for ii in range(d))

        @cache
        def dp(i, k):
            if k == 1:
                return change(0, i)
            return min(dp(j, k - 1) + change(j, i) for j in range((k - 1) * 2, i - 1))

        return dp(n, k)

if __name__ == "__main__":
    sln = Solution()
    print(sln.minimumChanges("abcab", 2))
