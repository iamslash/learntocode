// Copyright (C) 2023 by iamslash

// Input:
// [1, 2, 3]
// [1, 3, 2]
// Output:
// {"1":[2,3],"2":[3,2]}

// Idea: typeof(o1) is object | array | none of them.
//
// typeof([]) === "object"
// typeof({}) === "object"
//
// 0. o1 is not object and o2 is not object
// 1. o1 is object and o2 is not object
//    o1 is not object and o2 is object
// 2. o1 is array and o2 is not array
//    o1 is not array and o2 is array
// 3. Compare o1, o2 with idxs

// 67ms 58.40% 45.4MB 32.08%
function isObj(o: any) {
    return o !== null && typeof(o) === "object";
}
function objDiff(obj1: any, obj2: any): any {
    // base
    if (!isObj(obj1) && !isObj(obj2)) {
        if (obj1 === obj2) {
            return {};
        }
        return [obj1, obj2];
    }
    if (!isObj(obj1) || !isObj(obj2)) {
        return [obj1, obj2];
    }
    if (Array.isArray(obj1) !== Array.isArray(obj2)) {
        return [obj1, obj2];
    }
    // recursion
    const diffObj = {};
    for (const key in obj1) {
        if (key in obj2) {
            const childDiff = objDiff(obj1[key], obj2[key]);
            if (Object.keys(childDiff).length) {
                diffObj[key] = childDiff;
            }
        }
    }
    return diffObj;
};
