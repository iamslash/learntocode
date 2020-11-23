# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash

from typing import List, int, bool

# 36ms 100.00% 14.1MB 100.00%
# Hash Map
# O(N) O
class Solution:
    def canFormArray(self, A: List[int], pieces: List[List[int]]) -> bool:
        pieceMap = {e[0]: e for e in pieces}
        flatten = []
        for a in A:
            flatten += pieceMap.get(a, [])
        return flatten == A
        
