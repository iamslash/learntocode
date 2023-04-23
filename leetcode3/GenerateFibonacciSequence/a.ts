// Copyright (C) 2023 by iamslash

// 62ms 31.25% 44.3MB 31.25%
function* fibGenerator(): Generator<number, any, number> {
    // fib(0) === 0
    yield 0;
    // fib(1) === 1
    yield 1;
    let a: number = 0;
    let b: number = 1;
    while (true) {
        const c: number = a + b;
        a = b;
        b = c;
        yield c;
    }
};
