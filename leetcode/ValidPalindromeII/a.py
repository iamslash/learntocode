# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash 

# 176ms 29.68% 14.7MB 11.45%
# brute force
# O(N) O(1)
class Solution:
    def validPalindrome(self, s: str) -> bool:
        def palindrome(s: str, l: int, r: int) -> bool:
            while l < r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1
            return True
        i, j = 0, len(s) - 1
        while i < j:
            if s[i] != s[j]:
                return palindrome(s, i+1, j) or \
                    palindrome(s, i, j-1)
            i += 1
            j -= 1
        return True

if __name__ == "__main__":
    sln = Solution()
    print(sln.validPalindrome('aba'))  # True
    print(sln.validPalindrome('adba')) # True
    print(sln.validPalindrome('abc'))  # False
