// Copyright (C) 2023 by iamslash

// Idea:
//
// Debounce is a technique used to limit the frequency
// at which a particular function can be executed.

// 48ms 92.78% 42.1MB 19.58%
/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timeout = null;
    return function(...args) {
        clearTimeout(timeout);
        timeout = setTimeout(fn, t, ...args);
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */