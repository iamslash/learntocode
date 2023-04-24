// Copyright (C) 2023 by iamslash

// 137ms 100.00% 57.5MB 100.00% 
type MultidimensionalArray = (MultidimensionalArray | number)[]
function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
    if (!arr.length) {
        return;
    }
    const n = arr.length;
    for (let i = 0, q: MultidimensionalArray = []; q.length || i < n;) {
        let el = q.length ? q.shift() : arr[i++];
        if (Array.isArray(el)) {
            q.unshift(...el);
        } else {
            yield el!;
        }
    }
};

// 139ms 100.00% 62.3MB 100.00%
type MultidimensionalArray = (MultidimensionalArray | number)[]
function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
    for (let x of arr.flat(Infinity)) {
        yield x;
    }
}

// 238ms 76.00% 72.9MB 68.00%
type MultidimensionalArray = (MultidimensionalArray | number)[]
function* inorderTraversal(arr: MultidimensionalArray): Generator<number, void, unknown> {
    const n = arr.length;
    for (let i = 0; i < n; ++i) {
        const x = arr[i];
        if (typeof x == "number") {
            yield x;
        } else {
            yield* inorderTraversal(x);
        }
    }
}
