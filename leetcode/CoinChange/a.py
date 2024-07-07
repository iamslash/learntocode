# -*- coding: utf-8 -*-
# Copyright (C) 2024 by iamslash

from typing import List

# 819ms 47.07% 16.9MB 51.03%
# iterative dynamic programming
# O(AC) O(A)
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        C = [amount + 1 for _ in range(amount + 1)]
        C[0] = 0

        for expense in range(1, amount + 1):
            for coin in coins:
                if expense - coin >= 0:
                    C[expense] = min(C[expense], C[expense - coin] + 1)

        return C[amount] if C[amount] != amount + 1 else -1
