# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

# 244ms 100.00% 20.6MB 50.00%
# brute force
# O(N) O(1)
class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        idx, cnt = 0, 0
        if ruleKey == 'color':
            idx = 1
        elif ruleKey == 'name':
            idx = 2
        return sum([item[idx] == ruleValue for item in items])
        
if __name__ == "__main__":
    sln = Solution()
    # 1
    print(sln.countMatches([["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], "color", "silver"))
    # 2
    print(sln.countMatches( [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], "type", "phone"))
