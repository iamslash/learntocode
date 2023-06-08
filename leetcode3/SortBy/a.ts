// Copyright (C) 2023 by iamslash

// 164ms 100.00% 58MB 100.00%
function sortBy(arr: any[], fn: Function): any[] {
    return arr.sort((a, b) => fn(a) - fn(b));
};
