// Copyright (C) 2023 by iamslash

// 164ms 23.08% 48.1MB 23.08%
var partial = function(fn, args) {    
    return function(...restArgs) {
        let newArgs = args.map(arg => arg === '_' ? restArgs.shift() : arg);
        return fn(...newArgs.concat(restArgs));
    }
};
