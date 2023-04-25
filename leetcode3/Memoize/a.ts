// Copyright (C) 2023 by iamslash

// 360ms 76.55% 79.4MB 56.50%
type Fn = (...params: any) => any
function memoize(fn: Fn): Fn {
    const cache: Map<String, ReturnType<Fn>> = new Map();
    return function(...args) {
        const key = args.join(',');
        if (cache.has(key)) {
            return cache.get(key);
        }
        const val = fn(...args);
        cache.set(key, val);
        return val;
    }
}
