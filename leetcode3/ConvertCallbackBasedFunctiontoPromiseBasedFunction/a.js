// Copyright (C) 2023 by iamslash

var promisify = function(fn) {
    return async function(...args) {
        return new Promise((resolve, reject) => {
            function handler(value, error) {
                if (error) {
                    reject(error);
                } else {
                    resolve(value);
                }
            }
            fn(handler, ...args);
        });
    }
};

const asyncFunc = promisify(callback => callback(42));
asyncFunc().then(console.log); // 42
