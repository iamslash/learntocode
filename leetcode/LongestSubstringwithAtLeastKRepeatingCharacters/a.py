# -*- coding: utf-8 -*-

# 36ms 98.60%
class Solution:
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        for c in set(s):
            if s.count(c) < k:
                return max(self.longestSubstring(t, k) for t in s.split(c))
        return len(s)

if __name__ == "__main__":
    sln = Solution()
    print(sln.longestSubstring("aaabb", 3))
    print(sln.longestSubstring("ababbc", 2))
