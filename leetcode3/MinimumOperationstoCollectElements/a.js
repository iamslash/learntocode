// Copyright (C) 2023 by iamslash

// 59ms 48.75% 43.6MB 46.81%
// hash set
// O(N) O(N)
var minOperations = function(nums, k) {
    let n = nums.length;
    let numSet = new Set();
    for (let i = n - 1; i >= 0; --i) {
        if (nums[i] <= k) {
            numSet.add(nums[i]);
        }
        if (numSet.size == k) {
            return n - i;
        }
    }
    return -1;    
};