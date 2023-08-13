// Copyright (C) 2023 by iamslash

// // 55ms 67.21% 42.1MB 32.79%
// /**
//  * @param {Function} fn
//  * @param {number} delay
//  * @param {number} period
//  * @return {number} id
//  */
// let ids = [];
// let idx = 0;
// function customInterval(fn, delay, period) {
//     idx += 1;
//     function executeFn(passCnt) {
//         ids[idx] = setTimeout(() => {
//             fn();
//             executeFn(passCnt + 1);
//         }, delay + period * passCnt);    
//     }
//     executeFn(0);
//     return idx;
// }

// /**
//  * @param {number} id
//  */
// function customClearInterval(id) {
//     clearTimeout(ids[id]);   
// }

// 64ms 14.75% 42.1MB 32.79%
const idsMap = {};
let cnt = 0;
function customInterval(fn, delay, period) {
    cnt++;
    function executeFn(passCnt) {
        idsMap[cnt] = setTimeout(() => {
            fn();
            executeFn(passCnt + 1);
        }, delay + period * passCnt);    
    };
    executeFn(0);
    return cnt;
}
function customClearInterval(id) {
    clearTimeout(idsMap[id]);   
}


// Why this is right solution???
// 53ms 83.61% 42.2MB 27.87%
const idsMap = {};
function customInterval(fn, delay, period) {
    function executeFn(passCnt) {
        idsMap[1] = setTimeout(() => {
            fn();
            executeFn(passCnt + 1);
        }, delay + period * passCnt);    
    };
    executeFn(0);
    return 1;
}
function customClearInterval(id) {
    clearTimeout(idsMap[id]);   
}
