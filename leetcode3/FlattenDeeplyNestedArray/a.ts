// Copyright (C) 2023 by iamslash

// 199ms 63.89% 74.5MB 58.80%
type MultiDimensionalArray = (number | MultiDimensionalArray)[];
var flat = function (arr:  MultiDimensionalArray, n: number):  MultiDimensionalArray {
    if (n === 0) {
        return arr;
    }
    const rst: MultiDimensionalArray = [];
    for (let i = 0; i < arr.length; ++i) {
        const x = arr[i];
        if (typeof x === "number") {
            rst.push(x);
        } else {
            rst.push(...flat(x, n - 1));
        }
    }
    return rst;
};
