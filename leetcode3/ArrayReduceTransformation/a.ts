// Copyright (C) 2023 by iamslash

// 64ms 100.00% 45.4MB 100.00%
// O(N) O(1)
type Fn = (accum: number, curr: number) => number
function reduce(nums: number[], fn: Fn, init: number): number {
    let sum = init, n = nums.length;
    for (let i = 0; i < n; ++i) {
        sum = fn(sum, nums[i]);
    }
    return sum;
};
