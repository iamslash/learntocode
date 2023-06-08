// Copyright (C) 2023 by iamslash

// 85ms 100.00% 43.3M 100.00%
function cancellable(fn: Function, args: any[], t: number): Function {
    fn(...args);
    let id = setInterval(() => fn(...args), t);
    return () => clearInterval(id);
};
