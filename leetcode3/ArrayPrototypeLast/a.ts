// Copyright (C) 2023 by iamslash

// 55ms 100.00% 42.8MB 100.00%
// O(1) O(1)
declare global {
    interface Array<T> {
        last(): T | -1;
    }
}
Array.prototype.last = function() {
    const n = this.length;
    return n == 0 ? -1 : this[n - 1];
};

