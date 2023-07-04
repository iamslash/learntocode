// Copyright (C) 2023 by iamslash

// 58ms 100.00% 43.6MB 33.33%
type Fn = (...args) => any
declare global {
    interface Function {
        bindPolyfill(obj: Record<any, any>): Fn;
    }
}
Function.prototype.bindPolyfill = function(obj) {
    const fn = this;
    return function() {
        return fn.apply(obj, arguments);
    };
}
