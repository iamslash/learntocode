// Copyright (C) 2023 by iamslash

// 81ms 10.53% 45.5MB 59.65%
type ReturnObj = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}
function createCounter(init: number): ReturnObj {
    let cnt = init;
    return {
        increment: () => ++cnt,
        decrement: () => --cnt,
        reset: () => cnt = init,
    }    
};
