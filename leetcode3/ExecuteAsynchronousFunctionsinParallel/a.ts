// Copyright (C) 2023 by iamslash

// 76ms 86.79% 43.7MB 30.19%
async function promiseAll<T>(functions: (() => Promise<T>)[]): Promise<T[]> {
    return new Promise((resolve, reject) => {
        const rst = [];
        let cnt = 0;
        functions.forEach((fn, i) => {
            fn().then((result) => {
                rst[i] = result;
                cnt++;
                if (cnt === functions.length) {
                    resolve(rst);
                }
            }).catch((error) => reject(error));
        });
    });
};
