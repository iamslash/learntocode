// Copyright (C) 2023 by iamslash

// 84ms 12.79% 49.1MB 45.35%
function curry(fn: Function): Function {
    return function curried(...args: any[]) {
        if (args.length >= fn.length) {
            return fn(...args);
        }
        return function(...args2: any[]) {
            return curried(...args, ...args2);
        }
    }
}

// 68ms 68.60% 45MB 75.58%
function curry(fn: Function): Function {
    const argList: any[] = [];
    return function curried(...args: any[]) {
        argList.push(...args);
        if (argList.length == fn.length) {
            return fn(...argList);
        }
        return curried;
    }
}

// Why this is error after submit?
//             throw Error(msg);
//                   ^
// Error: An error occurred calling executing the curried function: curryFn is not a function
//     Line 50: Char 19 in solution.ts (Object.<anonymous>)
//     Line 16: Char 8 in runner.js (Object.runner)
//     Line 12: Char 26 in solution.ts (Object.<anonymous>)
//     at Module._compile (node:internal/modules/cjs/loader:1101:14)
//     at Object.Module._extensions..js (node:internal/modules/cjs/loader:1153:10)
//     at Module.load (node:internal/modules/cjs/loader:981:32)
//     at Function.Module._load (node:internal/modules/cjs/loader:822:12)
//     at Function.executeUserEntryPoint [as runMain] (node:internal/modules/run_main:81:12)
//     at node:internal/main/run_main_module:17:47
function curry(fn: Function): Function {
    const argList: any[] = [];
    return function curried(...args: any[]) {
        argList.push(...args);
        if (argList.length == fn.length) {
            return curried;
        }
        return fn(...argList);
    }
}
