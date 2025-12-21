# -*- coding: utf-8 -*-
# Copyright (C) 2025 by iamslash 

from typing import List

# 7ms 5.26% 17.40MB 98.33%
class Solution:
    def earliestTime(self, tasks: List[List[int]]) -> int:
        min_end_time = float('inf')

        for task in tasks:
            min_end_time = min(min_end_time, task[0] + task[1])

        return min_end_time

# 4ms 15.28% 17.42MB 98.33%
class Solution:
    def earliestTime(self, tasks: List[List[int]]) -> int:
        min_end_time = float('inf')

        return min(task[0] + task[1] for task in tasks)
        
def main():
    pass

if __name__ == "__main__":
    main()
