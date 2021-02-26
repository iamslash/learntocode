# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from collections import Counter
from typing import List

# bucket sort
# O(NlgN) O(N)
class Solution:
    def sortFeatures(self, features: List[str], responses: List[str]) -> List[str]:
        counter = Counter(features)
        for res in responses:
            res_set = set(res.split())
            for s in res_set:
                counter[s] += 1
        return sorted(features, key = lambda s: counter[s], reverse=True)
    
if __name__ == "__main__":
    sln = Solution()
    # ["touch","cooler","lock"]
    print(sln.sortFeatures(["cooler","lock","touch"], ["i like cooler cooler","lock touch cool","locker like touch"]))
    # ["a","aa","b","c"]
    print(sln.sortFeatures(["a","aa","b","c"], ["a","a aa","a a a a a","b a"]))
