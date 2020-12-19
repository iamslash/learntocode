# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 28ms 80.95% 14.1MB 70.59%
# math
# O(N) O(1)
class Solution:
    def uniquePaths(self, h: int, w: int) -> int:
        return math.factorial(h+w-2) // (math.factorial(h-1) * math.factorial(w-1))

if __name__ == "__main__":
    main()
