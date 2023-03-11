# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash

from typing import List

# 243ms 50.52% 14.1MB 48.96%
class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        ans = []
        for query in queries:
            for word in dictionary:
                if sum(c1 != c2 for c1, c2 in zip(query, word)) <= 2:
                    ans.append(query)
                    break
        return ans

if __name__ == '__main__':
    sln = Solution()
    print(sln.twoEditWords(["word","note","ants","wood"],
                           ["wood","joke","moat"]))
