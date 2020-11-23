# -*- coding: utf-8 -*-

# greedy approach
# 32ms 97.42% 13.8MB 100.00%
# O(N) O(1)
class Solution:
    def longestDecomposition(self, s : str) -> int:
        ans, l, r = 0, "", ""
        for i, j in zip(s, s[::-1]):
            l = l + i
            r = j + r
            if l == r:
                ans = ans + 1
                l = ""
                r = ""
        return ans

if __name__ == '__main__':
    Solution sln;
    print(sln.longestDecomposition("ghiabghi"))
