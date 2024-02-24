# -*- coding: utf-8 -*-
# Copyright (C) 2024 by iamslash 

# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None

# 59ms 17.79% 19.8MB 73.92%
# math
# O(N) O(1)
class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        s, t = p, q

        while s != t:
            if not s:
                s = q
            else:
                s = s.parent
            if not t:
                t = p
            else:
                t = t.parent

        return s

    
# 53ms 43.63% 19.9MB 73.92%
# math
# O(N) O(1)
class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        s, t = p, q

        while s != t:
            s = s.parent if s else q
            t = t.parent if t else p

        return s
