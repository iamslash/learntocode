// Copyright (C) 2023 by iamslash

// 68ms 100.00% 45MB 100.00%
function chunk(arr: any[], size: number): any[][] {
    const ans = [];
    const n = arr.length
    let idx = 0;
    while (idx < n) {
        ans.push(arr.slice(idx, idx + size));
        idx += size;
    }
    return ans;
};
