// Copyright (C) 2024 by iamslash

// 87ms 27.27% 54.1MB 60.61%
// hash map
// O(N) O(1)
function minOperations(nums: number[], k: number): number {
    const numCnts: number[] = new Array(101).fill(0);

    for (const num of nums) {
        if (num < k) {
            return -1;
        }
        if (num > k) {
            numCnts[num]++;
        }
    }

    let cnt = 0;
    for (let num = 0; num <= 100; ++num) {
        if (numCnts[num] > 0) {
            cnt++;
        }
    }

    return cnt;    
}

// 71ms 81.82% 53.4MB 96.97%
// hash set
// O(N) O(1)
function minOperations(nums: number[], k: number): number {
    const minNum = nums.reduce((a, c) => Math.min(a, c), Infinity);

    if (minNum < k) {
        return -1;
    }

    const numSet = new Set(nums);
    if (minNum === k) {
        return numSet.size - 1;
    }

    return numSet.size;
}
