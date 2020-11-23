# -*- coding: utf-8 -*-

# 588ms 89.22%
# O(N^2) O(N)
class Solution:
    def subarrayBitwiseORs(self, A: List[int]) -> int:
        ans = set()
        cur = {0}
        for a in A:
            cur = {a | b for b in cur} | {a}
            ans |= cur
        return len(ans)
