# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash

from typing import List

# 28ms 75.00% 14.2MB 25.00%
# brute force
# O(N) O(N)
class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        return "".join(word1) == "".join(word2)
        
if __name__ == "__main__":
    sln = Solution()
    print(sln.arrayStringsAreEqual(["ab", "c"], ["a", "bc"]))
