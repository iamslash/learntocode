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


# 70ms 90.39% 17.3MB 69.29%
# sliding window, hash map
# O(L * nm) O(n + L/m)
#   L: len of s
#   n: num of words
#   m: len of words[i]
class Solution:
    def findSubstring(self, s: str, words: list[str]) -> list[int]:
        if not s or not words: return []
        
        word_len = len(words[0])  # Length of each word
        num_words = len(words)  # Number of words
        substring_len = word_len * num_words  # Total length of substring formed by all words
        word_freq = defaultdict(int)
        
        # Count frequency of each word
        for word in words:
            word_freq[word] += 1
            
        result = []
        
        # Loop through the first word_len characters
        for i in range(word_len):
            left = i
            count = 0
            seen_words = defaultdict(int)
            
            # Slide the window of size substring_len
            for j in range(i, len(s) - word_len + 1, word_len):
                word = s[j:j + word_len]
                
                # If the word is part of words list
                if word in word_freq:
                    seen_words[word] += 1
                    count += 1
                    
                    # If a word is seen more times than it actually appears, move left pointer
                    while seen_words[word] > word_freq[word]:
                        seen_words[s[left:left + word_len]] -= 1
                        left += word_len
                        count -= 1
                    
                    # If all words match, add the starting index to the result
                    if count == num_words:
                        result.append(left)
                        # Move left pointer by one word to look for new window
                        seen_words[s[left:left + word_len]] -= 1
                        left += word_len
                        count -= 1
                else:
                    # If the word is not in words, reset the counters and move left pointer
                    seen_words.clear()
                    count = 0
                    left = j + word_len
        
        return result
