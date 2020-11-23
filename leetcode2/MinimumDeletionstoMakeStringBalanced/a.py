# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 468ms 78.51% 19.5MB 36.45%
# dynamic programming
# O(N) O(N)
class Solution:
    def minimumDeletions(self, s: str) -> int:
        a_cnt = s.count('a')
        b_cnt = 0
        del_cnt = [a_cnt + b_cnt]
        for c in s:
            if c == 'a':
                a_cnt -= 1
            else:
                b_cnt += 1
            del_cnt.append(a_cnt + b_cnt)
        return min(del_cnt)
