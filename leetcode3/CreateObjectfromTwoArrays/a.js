// Copyright (C) 2023 by iamslash

// 88ms 84.91% 55.8MB 58.49%
var createObject = function(keys, vals) {
    let n = keys.length;
    let obj = {};
    for (let i = 0; i < n; ++i) {
        if (!obj.hasOwnProperty(keys[i])) {
            obj[keys[i]] = vals[i];
        }
    }
    return obj;    
};