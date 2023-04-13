// Copyright (C) 2023 by iamslash

// Debounce delays fn with t millis.
// It reset timer whenever it is called.
// It throttlws call of fn.
// 69ms 34.78% 42.9MB 47.83%
// O(1) O(1)
type F = (...p: any[]) => any
function debounce(fn: F, t: number): F {
    let timeout: ReturnType<typeof setTimeout>;
    return function(...args) {
        clearTimeout(timeout);
        timeout = setTimeout(() => fn(...args), t);
    }
};
