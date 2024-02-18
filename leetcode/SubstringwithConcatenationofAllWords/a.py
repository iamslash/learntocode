# -*- coding: utf-8 -*-
# Copyright (C) 2024 by iamslash

from typing import List

# Idea: slding window
#
#     s: barfoothe
#        ......
#         ......
#          ......
#           ......
#
# 6415ms 14.20% 17.4MB 68.81%
# sliding window, hash map
# O(L * nm) O(n + L/m)
#   L: len of s
#   n: num of words
#   m: len of words[i]
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        ans = []
        wordCntMap = Counter(words)
        n, m = len(words), len(words[0])
        wndLen = m * n

        for i in range(len(s) - wndLen + 1):
            seenMap = {}
            j = 0
            while j < n:
                beg, end = i + j * m, i + (j + 1) * m
                word = s[beg:end]
                if word in wordCntMap:
                    seenMap[word] = seenMap.get(word, 0) + 1
                    if seenMap[word] > wordCntMap[word]:
                        break
                else:
                   break
                j += 1
            if j == n:
                ans.append(i)

        return ans

# Idea: slding window
#
#     s: barfoothe
#        ......
#           ......
#         ......
#          ......
#
# 2323ms 55.57% 17.4MB 68.81%
# sliding window, hash map
# O(L * nm) O(n + L/m)
#   L: len of s
#   n: num of words
#   m: len of words[i]
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        ans = []
        wordCntMap = Counter(words)
        n, m = len(words), len(words[0])
        wndLen = m * n

        for i in range(m):
            left = i
            while left + wndLen <= len(s):
                seenWndStr = s[left:left + wndLen]
                seenCntMap = Counter([seenWndStr[j:j + m] for j in range(0, wndLen, m)])
                if seenCntMap == wordCntMap:
                    ans.append(left)
                left += m

        return ans
