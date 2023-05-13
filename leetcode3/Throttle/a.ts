// Copyright (C) 2023 by iamslash

// 63ms 100.00% 43.1MB 100.00%
// setTimeout
type F = (...args: any[]) => void
function throttle(fn: F, t: number): F {
    let timeId = null;
    let storedArgs = null;

    function callWithStoredArgs() {
        if (storedArgs != null) {
            fn.apply(null, storedArgs);
            storedArgs = null;
            timeId = setTimeout(callWithStoredArgs, t);
        } else {
            timeId = null;
        }
    }
    
    return function (...args) {
        if (timeId == null) {
            fn.apply(null, args);
            timeId = setTimeout(callWithStoredArgs, t);
        } else {
            storedArgs = args;
        }
    }
};
