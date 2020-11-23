# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash

from typing import List

# DFS
# 116ms 49.86% 20.1MB 19.31%
class Solution:
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        forbidden_set = set(forbidden)
        toofar = max(forbidden) + b if a < b else x
        min_jump_cnt = -1
        position_cost = {}
        def dfs(pos = 0, jumped_from_back = False, jump_cnt = 0):
            nonlocal min_jump_cnt, toofar
            if pos < 0 or \
               pos in forbidden_set or \
               pos - b > toofar or \
               min_jump_cnt > -1 and jump_cnt > min_jump_cnt:
                return
            if pos == x:
                min_jump_cnt = jump_cnt if min_jump_cnt == -1 \
                    else min(min_jump_cnt, jump_cnt)
                return
            if jumped_from_back:
                dfs(pos + a, False, jump_cnt + 1)
                return
            elif pos not in position_cost:
                position_cost[pos] = jump_cnt
            elif jump_cnt >= position_cost[pos]:
                return
            else:
                position_cost[pos] = jump_cnt
            dfs(pos + a, False, jump_cnt+1)
            dfs(pos - b, True, jump_cnt+1)
            
        dfs()
        return min_jump_cnt
