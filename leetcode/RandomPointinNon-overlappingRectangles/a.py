# -*- coding: utf-8 -*-
# Copyright (C) 2019 by iamslash

import bisect
import random

class Solution:
    def __init__(self, rects):
        """
        :type rects: List[List[int]]
        """
        self.rects = rects
        self.range = []
        sum = 0
        for x1, y1, x2, y2 in rects:
            sum += (x2 - x1 + 1) * (y2 - y1 + 1)
            self.range.append(sum)        
    def pick(self):
        """
        :rtype: List[int]
        """
        # print(self.range)
        n = random.randint(0, self.range[-1] - 1)
        i = bisect.bisect(self.range, n) - 1
        x1, y1, x2, y2 = self.rects[i]
        n -= self.range[i]
        return [x1 + n % (x2 - x1 + 1), y1 + n / (x2 - x1 + 1)]
        
# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()


def main():
    R = [[1, 1, 5, 5]]
    sln = Solution(R)
    for i in range(10):
        print(sln.pick())

if __name__ == "__main__":
    main()
