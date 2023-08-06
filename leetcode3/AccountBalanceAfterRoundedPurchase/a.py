# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash 

# 39ms 66.67% 16.3MB 33.33%
# math
# O(1) O(1)
class Solution:
    def accountBalanceAfterPurchase(self, purchaseAmount: int) -> int:
        digit = purchaseAmount % 10
        if digit > 0:
            purchaseAmount -= digit
            if digit >= 5:
                purchaseAmount += 10
        return 100 - purchaseAmount
        
if __name__ == "__main__":
    sln = Solution()
    return sln.accountBalanceAfterPurchase(9)
