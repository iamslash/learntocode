// Copyright (C) 2023 by iamslash

//     l
// 3 4 5
//     h
//     m

// 59ms 100.00% 45MB 33.33%
// right most equal binary search
// O(lgN) O(1)
declare global {
    interface Array<T> {
        upperBound(target: number): number;
    }
}
Array.prototype.upperBound = function(target: number) {
    let lo = 0, hi = this.length - 1;
    while (lo < hi) {
        const mi = Math.floor((lo + hi + 1) / 2);
        if (this[mi] <= target) {
            lo = mi;
        } else {
            hi = mi - 1;
        }
    }
    if (this[lo] !== target) {
        return -1;
    }
    return lo
};
