# -*- coding: utf-8 -*-
# Copyright (C) 2025 by iamslash 

# 0ms 100.00% 18.00MB 21.43%
# hash map
# O(N) O(N)
class Solution:
    def filterCharacters(self, s: str, k: int) -> str:
        freqs = Counter(s)
        return ''.join(c for c in s if freqs[c] < k)

def main():
    pass

if __name__ == "__main__":
    main()
