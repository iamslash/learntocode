# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List
from collections import deque

# dfs, bfs
# O(HW) O(HW)
class Solution(object):
    def findShortestPath(self, master: 'gridMaster') -> int:
        """
        :type master: gridMaster
        :rtype: int
        """
        def dfs(y, x):
            pass
        def bfs(src, dst, board):
            pass
        src = (0, 0)
        dst = None
        board = collections.defaultdict(set)
        dfs(*src)
        if not dst:
            return -1
        return bfs(board, src, dst)
        
if __name__ == "__main__":
    main()
