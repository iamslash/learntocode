// Copyright (C) 2023 by iamslash

// 67ms 50.00% 42.8MB 50.00%
// brute force
// O(N) O(N)
function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    const rst = [], n = arr.length;
    for (let i = 0; i < n; ++i) {
        rst.push(fn(arr[i], i));
    }
    return rst;
};
