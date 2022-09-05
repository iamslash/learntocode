// Copyright (C) 2022 by iamslash

// 75ms 96.67% 43.5MB 56.67%
// sliding window, set
// O(N) O(N)
function findSubarrays(nums: number[]): boolean {
    let sumSet = new Set<number>();
    for (let i = 1; i < nums.length; ++i) {
        let sum = nums[i-1] + nums[i];
        if (sumSet.has(sum)) {
            return true;
        }
        sumSet.add(sum);
    }
    return false;
};
