// Copyright (C) 2025 by iamslash

/**
 * @param {number[]} nums
 * @return {number}
 */
// 0ms 100.00% 55.69MB 65.43%
// brute force
// O(N) O(N)
var alternatingSum = function(nums) {
    return nums.reduce((sum, num, i) =>
        i % 2 === 0 ? sum + num : sum - num, 0
    );
    
};