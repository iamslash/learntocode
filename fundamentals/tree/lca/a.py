# -*- coding: utf-8 -*-
# Copyright (C) 2022 by iamslash

 #        3
 #     /     \
 #    5       1
 #  /   \    / \
 # 6     2  0   8
 #      / \
 #     7   4

# 68ms 95.19% 26.3MB 35.81%
# lca
# O(N) O(lgN)
class Solution:
    def lowestCommonAncestor(self, u: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # base
        if u == None or u == p or u == q:
            return u
        # recursion
        l = self.lowestCommonAncestor(u.left, p, q)
        r = self.lowestCommonAncestor(u.right, p, q)
        if l != None and r != None:
            return u
        if l != None:
            return l
        return r

def main():
    pass

if __name__ == "__main__":
    main()
