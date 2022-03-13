# -*- coding: utf-8 -*-
# Copyright (C) 2022 by iamslash 

# 277ms 20.00% 14.1MB 100.00%
# sort, hash set
# O(NlgN) O(N)
class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        ans = set()
        for i, num in enumerate(nums):
            if num == key:
                ans.update(range(max(0, i-k), min(i+k+1, len(nums))))
        return sorted(list(ans))
        
def main():
    pass

if __name__ == "__main__":
    main()
