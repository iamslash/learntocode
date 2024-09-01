# -*- coding: utf-8 -*-
# Copyright (C) 2024 by iamslash

from collections import Counter, defaultdict
from typing import List

# 263ms 73.32% 16.6MB 98.77%
# recursive dynamic programming
# O(N * 2^M) O(2^M + N)
# N: stickers count
# M: target length 
class Solution:
    
    def dfs(self, cache, sticker_freqs, target):
        # base
        if not target:
            return 0
        
        # memo
        if target in cache:
            return cache[target]
        
        # recursion
        target_freq = Counter(target)

        min_cnt = float('inf')
        for sticker_freq in sticker_freqs:
            if sticker_freq[target[0]] == 0:
                continue

            new_target_freq = target_freq - sticker_freq            
            new_target = ''.join(char * count for char, count in new_target_freq.items())

            if new_target != target:
                cnt = self.dfs(cache, sticker_freqs, new_target)
                if cnt != -1:
                    min_cnt = min(min_cnt, cnt + 1)

        cache[target] = -1 if min_cnt == float('inf') else min_cnt
        return cache[target]
    
    def minStickers(self, stickers: List[str], target: str) -> int:
        sticker_freqs = [Counter(sticker) for sticker in stickers]
        cache = {}
        return self.dfs(cache, sticker_freqs, target)
