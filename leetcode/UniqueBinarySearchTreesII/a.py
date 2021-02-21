# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# dfs
# O(N) O(N)
class Solution:
    def dfs(self, roots: List[TreeNode]) -> List[TreeNode]:
        # base
        if not roots:
            return [None]
        # recursion
        ans = []
        for i in range(len(roots)):
            for left in self.dfs(roots[:i]):
                for right in self.dfs(roots[i+1:]):
                    u = TreeNode(roots[i])
                    u.left = left
                    u.right = right
                    ans += [u]
        return ans
    def generateTrees(self, n: int) -> List[TreeNode]:
        return self.dfs([i for i in range(1, n+1)])

if __name__ == '__main__':
    sln = Solution()
    print(sln.generateTrees(3))
