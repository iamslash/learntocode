# -*- coding: utf-8 -*-
# Copyright (C) 2022 by iamslash

# 371ms 66.81% 14.9MB 81.23%
# heap
# O(NlgN) O(N)
class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        heapify(sticks)
        ans = 0
        while len(sticks) > 1:
            cost = heappop(sticks) + heappop(sticks)
            heappush(sticks, cost)
            ans += cost
        return ans

def main():
    pass

if __name__ == "__main__":
    main()
