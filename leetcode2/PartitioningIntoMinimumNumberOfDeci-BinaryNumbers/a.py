# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 64ms 50.00% 14.8MB 25.00%
# greedy algorithm
# O(N) O(1)
class Solution:
    def minPartitions(self, s: str) -> int:
        return int(max(s))
    
if __name__ == "__main__":
    sln = Solution()
    # 3
    print(sln.minPartitions(32))
    # 8
    print(sln.minPartitions(82734))
    # 9
    print(sln.minPartitions(27346209830709182346)) 
