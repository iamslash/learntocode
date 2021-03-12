# -*- coding: utf-8 -*-
# Copyright (C) 2021 by iamslash 

# 40ms 81.75% 14.8MB 78.85%
# brute force
# O(N) O(N)
class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        S = S.replace("-", "")
        n = len(S)
        firstlen = n % K
        ans = S[:firstlen].upper() + "-" if firstlen > 0 else ""
        for i in range(firstlen, n, K):
            ans += S[i:i+K].upper() + "-"
        return ans[:-1]
        
if __name__ == "__main__":
    sln = Solution()
    # 5F3Z-2E9W
    print(sln.licenseKeyFormatting("5F3Z-2e-9-w", 4))
    # 2-5G-3J
    print(sln.licenseKeyFormatting("2-5g-3-J", 2))
    # "A-0001-AFDS"
    print(sln.licenseKeyFormatting("a0001afds-", 4))
