// Copyright (C) 2025 by iamslash

// 0ms 100.00% 56.40MB 91.85%
// brute force
// O(N) O(N)
function alternatingSum(nums: number[]): number {
    return nums.reduce((sum, num, idx) =>
        idx % 2 === 0 ?
        sum + num :
        sum - num, 0);
};
