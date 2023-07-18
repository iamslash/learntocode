// Copyright (C) 2023 by iamslash

// Idea:
//
// Array.isArray
// typeof(obj) === 'object' && obj !== null
// obj === undefined

// 63ms 91.30% 48MB 50.00%
var undefinedToNull = function(obj) {
    if (Array.isArray(obj)) {
        return obj.map(function(elem) {
            return undefinedToNull(elem);
        });        
    } else if (typeof(obj) === 'object' && obj !== null) {
        var rst = {};
        for (var key in obj) {
            if (obj.hasOwnProperty(key)) {
                rst[key] = undefinedToNull(obj[key]);
            }
        }
        return rst;
    } else if (obj === undefined) {
        return null;
    }
    return obj;
};
