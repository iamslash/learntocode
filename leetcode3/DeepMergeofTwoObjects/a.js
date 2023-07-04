// Copyright (C) 2023 by iamslash

// 136ms 40.00% 66.6MB 22.50%
// object, array, other-type
// 3 * 3 = 9 kinds
const isObj = (obj) => typeof(obj) === 'object';
const isArray = (obj) => Array.isArray(obj);
var deepMerge = function(obj1, obj2) {
    // base
    if (obj1 === null || obj2 === null) {
        return obj2;
    }
    if (!isObj(obj1) || typeof(obj1) !== typeof(obj2)) {
        return obj2;
    }
    if ((isArray(obj1) && !isArray(obj2)) || (!isArray(obj1) && isArray(obj2))) {
        return obj2;
    }   
    // recursion
    var rst = isArray(obj1) ? [] : {};
    Object.keys(obj1).forEach(key => {
        if (obj2[key] === undefined) {
            rst[key] = obj1[key];
        } else if (!isObj(obj1[key]) && obj2[key] !== undefined) {
            rst[key] = obj2[key];
        } else if (isObj(obj1[key]) && isObj(obj2)) {
            rst[key] = deepMerge(obj1[key], obj2[key]);
        }
    });
    Object.keys(obj2).forEach(key => !obj1[key] ? rst[key] = obj2[key] : null);
    return rst;
}
