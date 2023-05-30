// Copyright (C) 2023 by iamslash


// Idea:
//
// Candidates of obj
// Undefined, "undefined"
// Null,      "object"
// Boolean,   "boolean"
// Number,    "number"
// BigInt,    "bigint"
// String,    "string"
// Symbol,    "symbol"
// Function,  "function"
// Object,    "object"
//
// typeof of Null, Object return "object".

// 111ms 46.67% 54.1MB 60.00%
type Obj = Record<any, any>;
function compactObject(obj: Obj): Obj {
    // base
    if (Array.isArray(obj)) {
        return obj.filter(Boolean).map(compactObject); 
    }
    if (obj === null || typeof(obj) !== 'object') {
        return obj;
    }
    // recursion
    const rst = {};
    for (const key in obj) {
        const val = compactObject(obj[key]);
        if (Boolean(val)) {
            rst[key] = val;
        }
    }
    return rst;
};
