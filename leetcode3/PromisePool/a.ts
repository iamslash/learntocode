// Copyright (C) 2023 by iamslash

// 76ms 13.25% 42.5MB 91.57%
type F = () => Promise<any>;
function promisePool(functions: F[], n: number): Promise<any> {
    const next: F = () => functions[n++]?.().then(next);
    return Promise.all(functions.slice(0, n).map(f => f().then(next)));
};
