# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash

from typing import List

#       k: 1
# day2pos: 1 3 2
#          l   r
# pos2day: 1 3 2
#            i
#  minday:

# 972ms 90.44% 16.8MB 48.21%
# Sliding window
# O(N) O(N)
class Solution:
    def kEmptySlots(self, day2pos: List[int], k: int) -> int:
        n = len(day2pos)
        pos2day = [0]*n
        for d in range(n):
            pos2day[day2pos[d]-1] = d+1
        # print(pos2day)
        i, l, r, minday = 1, 0, k+1, n+1
        while r < n:
            # print(f'i:{i}, l:{l}, r:{r}, minday:{minday}')
            # move slide
            if pos2day[i] < pos2day[l] or pos2day[i] <= pos2day[r]:
                if i == r:
                    minday = min(minday, max(pos2day[l], pos2day[r]))
                l = i
                r = l + k + 1
            i += 1
        # print(f'i:{i}, l:{l}, r:{r}, minday:{minday}')
        return -1 if minday == n+1 else minday
    
if __name__ == "__main__":
    sln = Solution()
    # 2
    print(sln.kEmptySlots([1,3,2], 1))
    # -1
    print(sln.kEmptySlots([1,2,3], 1))
