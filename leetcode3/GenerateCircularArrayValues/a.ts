// Copyright (C) 2023 by iamslash

// 52ms 100.00% 44.9MB 100.00%
function* cycleGenerator(arr: number[], startIndex: number): Generator<number, void, number> {
    let idx = startIndex;
    const n = arr.length;
    while (true) {
        const jump = yield arr[idx];
        // jump might be big negative
        idx = (idx + n + jump % n) % n;
    }
};
