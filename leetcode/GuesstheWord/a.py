# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash 

# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Master:
#     def guess(self, word: str) -> int:

# >>> from collections import Counter
# >>> wordlist = ["acckzz","ccbazz","eiowzz","abcczz"]
# >>> w[0] for w in wordlist
# >>> freqlist = [Counter(w[i] for w in wordlist) for i in range(6)]
# >>> pprint.pprint(freqlist)
# [Counter({'a': 2, 'c': 1, 'e': 1}),
#  Counter({'c': 2, 'i': 1, 'b': 1}),
#  Counter({'c': 2, 'b': 1, 'o': 1}),
#  Counter({'k': 1, 'a': 1, 'w': 1, 'c': 1}),
#  Counter({'z': 4}),
#  Counter({'z': 4})]
# >>> max(wordlist, key = lambda w: sum(freqlist[i][c] for i, c in enumerate(w))) 
# 'acckzz'

# wordlist: aaabbb aaaccc
# freqlist: a a a b b b
#           2 2 2 1 1 1
#                 c c c
#                 1 1 1

from typing import List

# 32ms 76.01% 14.4MB 36.14
class Solution:
    def findSecretWord(self, wordlist: List[str], master: 'Master') -> None:
        def match(w1, w2):
            return sum(a == b for a, b in zip(w1, w2))
        n = 0
        while n < 6:
            # freqmaplist[i][c]: the count of c character and i-th of word[*]
            freqmaplist = [collections.Counter(w[i] for w in wordlist) for i in range(6)]
            guess = max(wordlist, key = lambda w: sum(freqmaplist[i][c] for i, c in enumerate(w)))
            n = master.guess(guess)
            wordlist = [w for w in wordlist if match(w, guess) == n]

if __name__ == "__main__":
    from collections import Counter
    from pprint import pprint
    wordlist = ["aaabbb","aaaccc","aaaddd","aaaeee"]
    while True:
        input()
        freqmaplist = [Counter(w[i] for w in wordlist) for i in range(6)]
        pprint(freqmaplist)
        guess = max(wordlist, key = lambda w: sum(freqmaplist[i][c] for i, c in enumerate(w)))
        print(guess)
