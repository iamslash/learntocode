# -*- coding: utf-8 -*-
# Copyright (C) 2022 by iamslash

from typing import List


# intervals: 0,30 5,10 15,20
#                     i
#      begs:  0  5 15
#      ends: 10 20 30
#                j

# 133ms 29.70% 17.5MB 52.66%
# sort, two pointers
# O(NlgN) O(1)
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        n, ans = len(intervals), 0
        begs, ends = [0] * n, [0] * n
        for i in range(n):
            begs[i], ends[i] = intervals[i][0], intervals[i][1]
        begs.sort()
        ends.sort()
        j = 0
        for i in range(n):
            if begs[i] < ends[j]:
                ans += 1
            else:
                j += 1
        return ans            
        
if __name__ == "__main__":
    pass
