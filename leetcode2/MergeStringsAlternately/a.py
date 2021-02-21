# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash 

# 16ms 100.00% 14.3MB 33.33%
# brute force
# O(N) O(1)
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        ans = ""
        for a, b in zip(word1, word2):
            ans += a + b
        min_len = min(len(word1), len(word2))
        additional = ""
        if len(word1) > len(word2):
            additional = word1[min_len:]
        else:
            additional = word2[min_len:]
        return ans + additional

# 24ms 100.00% 14.4MB 33.33%
# brute force
# O(N) O(1)
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        return ''.join(a + b for a, b in zip_longest(word1, word2, fillvalue=''))
    
if __name__ == "__main__":
    sln = Solution()
    # apbqcr
    print(sln.mergeAlternately('abc', 'pqr'))
    # apbqrs
    print(sln.mergeAlternately('ab', 'pqrs'))
    # apbqcd
    print(sln.mergeAlternately('abcd', 'pq'))
    # apqr
    print(sln.mergeAlternately('a', 'pqr'))
