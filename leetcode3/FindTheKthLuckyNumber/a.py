# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash 

# for i in range(10):
# ...     print(bin(i)[3:].replace('0', '4').replace('1', '7'))
# ...
# 4
# 7
# 44
# 47
# 74
# 77
# 444
# 447

# 43ms 99.26% 16.4MB 11.76%
class Solution:
    def kthLuckyNumber(self, k: int) -> str:
        return bin(k + 1)[3:].replace('0', '4').replace('1', '7')
