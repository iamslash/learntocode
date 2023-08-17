// Copyright (C) 2023 by iamslash

/**
 * @param {Array<Function>} functions
 * @param {number} ms
 * @return {Array<Function>}
 */

// 61ms 42.3MB
// promise
var delayAll = function(functions, ms) {
    return functions.map(func => {
        return () => {
            return new Promise((resolve, reject) => {
                setTimeout(() => {
                    func()
                        .then(result => resolve(result))
                        .catch(error => reject(error));
                }, ms);
            });
        };
    });    
};

// 65ms 42.5MB
// async/await
var delayAll = function(functions, ms) {
    return functions.map(func => {
        return async () => {
            await new Promise(resolve => setTimeout(resolve, ms));
            try {
                const result = await func();
                return Promise.resolve(result);
            } catch (error) {
                return Promise.reject(error);
            }
        };
    });
};