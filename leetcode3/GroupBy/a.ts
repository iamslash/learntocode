// Copyright (C) 2023 by iamslash

// 166ms 19.10% 63.8MB 48.31%
declare global {
    interface Array<T> {
        groupBy(fn: (item: T) => string): Record<string, T[]>
    }
}
Array.prototype.groupBy = function(fn) {
    const groupMap = {};
    for (let i = 0; i < this.length; ++i) {
        const key = fn(this[i]);
        groupMap[key] = groupMap[key] || [];
        groupMap[key].push(this[i]);
    }
    return groupMap;
}
