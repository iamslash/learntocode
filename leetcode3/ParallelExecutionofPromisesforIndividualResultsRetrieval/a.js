// Copyright (C) 2023 by iamslash

// 71ms 10.34% 42.3MB 27.59%
var promiseAllSettled = function(fns) {
     return new Promise((resolve, reject) => {
        const n = fns.length;
        let i = 0;
        const ans = Array(n);
        fns.forEach((fn, idx) => {
            fn().then((result) => {
                ans[idx] = {"status": "fulfilled", "value": result};
                if (++i === n) {
                    resolve(ans);
                }
            },
            (error) => {
                ans[idx] = {"status": "rejected", "reason": error};
                if (++i === n) {
                    resolve(ans);
                }
            });
        });
    });
};
