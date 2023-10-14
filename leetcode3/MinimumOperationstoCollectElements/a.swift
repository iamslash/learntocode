/* Copyright (C) 2023 by iamslash */

import Foundation

// 10ms 55.56% 14.3MB 16.67%
// hash set
// O(N) O(N)
class Solution {
    func minOperations(_ nums: [Int], _ k: Int) -> Int {
        let n: Int = nums.count
        var numSet: Set<Int> = Set<Int>()
        for i in (0...n-1).reversed() {
            if nums[i] <= k {
                numSet.insert(nums[i])
            }
            if numSet.count == k {
                return n - i
            }
        }
        return -1
    }
}
