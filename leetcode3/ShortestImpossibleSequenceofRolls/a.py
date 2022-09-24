# -*- coding: utf-8 -*-
# Copyright (C) 2022 by iamslash

from typing import List

# 2251ms 6.48% 28.3MB 38.25%
# hash set
# O(N) O(K)
class Solution:
    def shortestSequence(self, rolls: List[int], k: int) -> int:
        ans = 1
        diceSet = set()
        for roll in rolls:
            diceSet.add(roll)
            if len(diceSet) == k:
                diceSet = set()
                ans += 1
        return ans
