// Copyright (C) 2023 by iamslash

// 64ms 35.71% 43.5MB 19.05%
function once<T extends (...args: any[]) => any>(fn: T): 
((...args: Parameters<T>) => ReturnType<T> | undefined) {
    let done = false;
    return function (...args) {
        if (done === true) {
            return undefined;
        }
        done = true;
        return fn(...args);
    };
}
