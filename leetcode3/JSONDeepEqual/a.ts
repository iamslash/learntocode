// Copyright (C) 2023 by iamslash

// json types:
//   string
//   number
//   boolean
//   list
//   map
//
// const a = {}
// const b = [1,2,3]
// typeof a // object
// typeof b // object
// Array.isArray(a) // false
// Array.isArray(g) // true

// 105ms 17.54% 51.6MB 15.79%
function areDeeplyEqual(o1: any, o2: any): boolean {
    if ((typeof o1) != (typeof o2)) {
        return false;
    }
    if (o1 === null && o2 === null) {
        return true;
    }
    switch (typeof o1) {
        case "undefined":
        case "string":
        case "number":
        case "boolean":
            return o1 === o2;
    }
    if (Array.isArray(o1) || Array.isArray(o2)) {
        if (!Array.isArray(o1) || !Array.isArray(o2) || o1.length != o2.length) {
            return false;
        }
        return o1.every((e: any, i: number) => areDeeplyEqual(e, o2[i]));
    }
    const keys = Array.from(new Set([...Object.keys(o1), ...Object.keys(o2)]));
    return keys.every(k => areDeeplyEqual(o1[k], o2[k]));
};
