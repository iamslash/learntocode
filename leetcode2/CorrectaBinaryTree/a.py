# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 188ms 46.74% 27.4MB 38.04%
# BFS
# O(N) O(N)
class Solution:
    def correctBinaryTree(self, root: TreeNode) -> TreeNode:
        q = [root]
        while q:
            child_nodes = []
            for u in q:
                if u.left:
                    child_nodes.append(u.left)
                if u.right:
                    child_nodes.append(u.right)
            for u in child_nodes:
                if u.right in child_nodes:
                    for p in q:
                        if p.left == u:
                            p.left = None
                        if p.right == u:
                            p.right = None
                    return root
            q = child_nodes
            
# 184ms 58.70% 27.6MB 38.04%
# BFS
# O(N) O(N)
class Solution:
    def correctBinaryTree(self, root: TreeNode) -> TreeNode:
        q = deque([root])
        while q:
            u = q.popleft()
            if u.right:
                if u.right.right in q:
                    u.right = None
                    return root
                else:
                    q.append(u.right)
            if u.left:
                if u.left.right in q:
                    u.left = None
                    return root
                else:
                    q.append(u.left)
        return root
