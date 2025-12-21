# -*- coding: utf-8 -*-
# Copyright (C) 2025 by iamslash

from typing import List

# 3ms 27.19% 17.13MB 100.00%
# O(N) O(1)
class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        n = len(s)
        positions = [-1] * 26

        for pos in range(n):
            idx = ord(s[pos]) - ord('a')

            if positions[idx] >= 0:
                dist = pos - positions[idx] - 1
                if distance[idx] != dist:
                    return False

            positions[idx] = pos

        return True

# 4ms 13.16% 17.23MB 99.12%
# hash map
# O(N) O(1)
class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        posMap = {}

        for i in range(len(s)):
            idx = ord(s[i]) - ord('a')
            if idx not in posMap:
                posMap[idx] = i
            else:
                if i - posMap[idx] - 1 != distances[idx]:
                    return False
        return True

# 0ms 100.00% 17.14MB 100.00%
# hash map
# O(N) O(1)
class Solution:
    def checkDistances(self, s: str, distances: List[int]) -> bool:
        positions = [-1] * 26

        for pos, char in enumerate(s):
            idx = ord(char) - ord('a')

            if positions[idx] != -1:
                if pos - positions[idx] - 1 != distances[idx]:
                    return False
            else:
                positions[idx] = pos;
                
        return True
        
def main():
    pass

if __name__ == "__main__":
    main()
