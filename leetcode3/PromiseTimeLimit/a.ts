// Copyright (C) 2023 by iamslash

// 63ms 100.00% 43.5MB 100.00%
// O(1) O(1)
type Fn = (...params: any[]) => Promise<any>;
function timeLimit(fn: Fn, t: number): Fn {
    return async function(...args) {
        const orgPromise = fn(...args);
        const timedPromise = new Promise((_, reject) => {
            setTimeout(() => { reject("Time Limit Exceeded") }, t);
        });
        return Promise.race([orgPromise, timedPromise]);
    }
};
