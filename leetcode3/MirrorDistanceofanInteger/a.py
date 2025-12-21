# -*- coding: utf-8 -*-
# Copyright (C) 2025 by iamslash

# 0ms 100.00% 8.60MB 36.36%
# math
# O(N) O(1)
class Solution:
    def mirrorDistance(self, n: int) -> int:
        org_num = n
        rev_num = 0

        while n > 0:
            digit = n % 10
            n //= 10

            rev_num = rev_num * 10 + digit

        return abs(org_num - rev_num)

def main():
    pass

if __name__ == "__main__":
    main()
