// Copyright (C) 2023 by iamslash

// 59ms 66.76% 44.8MB 33.33%
// O(N) O(N)
function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    const n = arr.length;
    const rst = [];
    for (let i = 0; i < n; ++i) {
        if (fn(arr[i], i)) {
            rst.push(arr[i]);
        }
    }
    return rst;
};
