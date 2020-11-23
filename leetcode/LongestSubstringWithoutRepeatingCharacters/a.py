# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 60ms 69.44% 142MB 77.27%
# two pointers
# O(N) O(1)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i, ans, n = 0, 0, len(s)
        cnt_map = dict()
        for j in range(n):
            if s[j] not in cnt_map:
                cnt_map[s[j]] = j
            else:
                i = max(i, cnt_map[s[j]]+1)
                cnt_map[s[j]] = j
            ans = max(ans, j - i + 1)
        return ans
    
if __name__ == "__main__":
    sln = Solution()
    print(sln.lengthOfLongestSubstring("abcabcbb"))
    print(sln.lengthOfLongestSubstring("bbbbbb"))
    print(sln.lengthOfLongestSubstring("pwwkew"))
    print(sln.lengthOfLongestSubstring(""))
    
