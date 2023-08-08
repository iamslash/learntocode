// Copyright (C) 2023 by iamslash

// Time LImit Exceeded
/**
 * @param {Function} fn
 * @param {number} delay
 * @param {number} period
 * @return {number} id
 */
let ids = []
function customInterval(fn, delay, period) {
    let len = ids.length;
    let idx = 0;
    function executeFn() {
        fn();
        idx += 1;
        ids[len] = setTimeout(executeFn, delay + idx * period);
    }
    idx[0] = setTimeout(executeFn, delay);
    return 0;
}

/**
 * @param {number} id
 */
function customClearInterval(id) {
    clearTimeout(ids[id]);   
}
