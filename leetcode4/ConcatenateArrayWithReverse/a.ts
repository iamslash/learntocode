// Copyright (C) 2026 by iamslash

// linear traversal
// O(N) O(N)
// 3ms 13.89% 60.73MB 23.61%
function concatWithReverse(nums: number[]): number[] {
    const n = nums.length;
    const ans: number[] = new Array(2 * n);

    for (let i = 0; i < n; ++i) {
        ans[i] = nums[i];
        ans[n + i] = nums[n - i - 1];
    }

    return ans;
};

function main() {
    console.log("Hello World");
    console.log(concatWithReverse([1, 2, 3]));
}

main();
