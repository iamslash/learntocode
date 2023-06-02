// Copyright (C) 2023 by iamslash

// 69ms 100.00% 43.1MB 100.00%
function cancellable(fn: Function, args: any[], t: number): Function {
    let canceled = false;
    setTimeout(() => {
        if (canceled) {
            return;
        }
        return fn(...args);
    }, t);
    return () => canceled = true;
};
