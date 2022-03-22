# -*- coding: utf-8 -*-
# Copyright (C) 2022 by iamslash

from typing import List

# 944ms 12.82% 18.9MB 63.65%
# hash map
# O(N) O(N)
class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        n, MOD, ans = len(arr), 1000000007, 0
        lefts, rights = [0] * n, [0] * n
        for i in range(n):
            j = i - 1
            while j >= 0 and arr[j] > arr[i]:
                j = lefts[j]
            lefts[i] = j
        for i in range(n-1, -1, -1):
            j = i + 1
            while j < n and arr[i] <= arr[j]:
                j = rights[j]
            rights[i] = j
            # calculcate ans
            ans = (ans + arr[i] * (i - lefts[i]) * (rights[i] - i)) % MOD
        return ans

# 590ms 66.89% 18.9MB 41.27%
# mono stack
# O(N) O(N)
class Solution:
    def sumSubarrayMins(self, A: List[int]) -> int:
        A, MOD = [0] + A, 1000000007
        ans = [0] * len(A)
        stck = [0]
        for i in range(len(A)):
            while A[stck[-1]] > A[i]:
                stck.pop()
            j = stck[-1]
            ans[i] = ans[j] + (i - j) * A[i]
            stck.append(i)
        return sum(ans) % MOD
    
def main():
    pass

if __name__ == "__main__":
    main()
