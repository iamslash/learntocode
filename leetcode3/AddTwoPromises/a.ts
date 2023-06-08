// Copyright (C) 2023 by iamslash

// 74ms 100.00% 43mb 100.00%
async function addTwoPromises(promise1: Promise<number>,
                              promise2: Promise<number>): Promise<number> {
    return Promise.all([promise1, promise2]).then((values) => {
        return values.reduce((acc, cur) => acc + cur, 0);
    });
};
