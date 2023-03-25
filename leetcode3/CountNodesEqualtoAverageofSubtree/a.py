# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

        # 44ms 77.02% 15.1MB 67.65%
# dfs
# O(N) O(lgN)
class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        best = 0

        def dfs(u):
            nonlocal best
            # base
            if u == None:
                return 0, 0
            
            # recursion
            lsum, lcnt = dfs(u.left)
            rsum, rcnt = dfs(u.right)
            sum = lsum + rsum + u.val
            cnt = lcnt + rcnt + 1
            if sum // cnt == u.val:
                best += 1

            return sum, cnt    
                
        dfs(root)
        return best

