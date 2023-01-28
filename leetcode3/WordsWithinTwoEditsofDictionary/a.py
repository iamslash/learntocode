# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash

from typing import List

# 382ms 35.25% 14MB 93.17%
# brute force
# O(QD) O(Q)
# Q: the number of queries
# D: the number of dictionary
class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        ans = []
        for query in queries:
            if any(sum(c1 != c2 for c1, c2 in zip(query, word)) <= 2 for word in dictionary):
                ans.append(query)
        return ans

if __name__ == "__main__":
    q = "hello"
    d = "world"
    for c1, c2 in zip(q, d):
        print(c1, c2)
        # h w
        # e o
        # l r
        # l l
        # o d
    print(sum(c1 != c2 for c1, c2 in zip(q, d)))
    # 4
