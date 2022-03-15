# -*- coding: utf-8 -*-
# Copyright (C) 2022 by iamslash

# 64ms 94.36% 14.8MB 58.15%
# sort
# O(NlgN) O(1)
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.sort()
        return nums[-k]

def main():
    pass

if __name__ == "__main__":
    main()
