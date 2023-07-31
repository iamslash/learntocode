# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash 

# 6459ms 25.00% 14.2MB 50.00%
# disjoint set
# O(N^2) O(N)
class DisjointSet:
    def __init__(self, n):
        self.prnts = list(range(n))

    def find(self, u):
        if self.prnts[u] == u:
            return u
        self.prnts[u] = self.find(self.prnts[u])
        return self.prnts[u]

    def merge(self, u, v):
        u = self.find(u)
        v = self.find(v)
        self.prnts[u] = v
        
class Solution:
    def friendRequests(self, n, restrictions, requests):
        disjointSet, ans = DisjointSet(n), []
        for u, v in requests:
            u, v = disjointSet.find(u), disjointSet.find(v)
            friend = True
            for p, q in restrictions:
                p, q = disjointSet.find(p), disjointSet.find(q)
                if set([u, v]) == set([p, q]):
                    friend = False
                    break
            ans.append(friend)
            if friend is True:
                disjointSet.merge(u, v)
        return ans

if __name__ == "__main__":
    print("Hello World")
