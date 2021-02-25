# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from collections import Counter
from typing import List

# class Solution:
#     def popularity(self, s):
#         cnt = 0
#         for res_set in self.res_sets:
#             if s in res_set:
#                 cnt += 1
#         return cnt
    
#     def sortFeatures(self, features: List[str], responses: List[str]) -> List[str]:
#         self.res_sets = []
#         for res in responses:
#             self.res_sets.append(set(res.split(' ')))
#         return sorted(features, key = lambda s: self.popularity(s))

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
