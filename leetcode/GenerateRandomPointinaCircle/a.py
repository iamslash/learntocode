# -*- coding: utf-8 -*-
# Copyright (C) 2019 by iamslash

import random

# r^2 = x^2 + y^2
# Time Limit Exceed 
class Solution:

    def __init__(self, radius, x_center, y_center):
        """
        :type radius: float
        :type x_center: float
        :type y_center: float
        """
        self.x_min = x_center - radius
        self.x_max = x_center + radius
        self.y_min = y_center - radius
        self.y_max = y_center + radius
        self.r = radius
        self.x_cen = x_center
        self.y_cen = y_center

    def randPoint(self):
        """
        :rtype: List[float]
        """
        while True:
            x = random.uniform(self.x_min, self.x_max)
            y = random.uniform(self.y_min, self.y_max)
            if (x - self.x_cen) ** 2 + (y - self.y_cen) ** 2 <= self.r:
                return [x, y]

# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()

def main():
    sln = Solution(1, 0, 0)
    for i in range(10):
        print(sln.randPoint())

if __name__ == "__main__":
    main()
