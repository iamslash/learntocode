# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash 

# 4204ms 100.00% 14.4MB 100.00%
# hash map
# O(N^2) O(1)
class Solution:
    def beautySum(self, s: str) -> int:
        ans = 0
        for i in range(len(s)):
            freq = [0]*26
            for j in range(i, len(s)):
                freq[ord(s[j])-ord('a')] += 1
                ans += max(freq) - min(x for x in freq if x > 0)
        return ans
        
if __name__ == "__main__":
    sln = Solution()
    # 5
    print(sln.beautySum("aabcb"))
    # 17
    print(sln.beautySum("aabcbaa"))
