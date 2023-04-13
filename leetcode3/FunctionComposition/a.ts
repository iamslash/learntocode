// Copyright (C) 2023 by iamslash

// 71ms 100.00% 46.4MB 100.00%
// O(N) O(1)
type F = (x: number) => number;
function compose(functions: F[]): F {
    return function(x: number): number {
        let rst = x, n = functions.length;
        for (let i = n - 1; i >= 0; --i) {
            rst = functions[i](rst);
        }
        return rst;
    }
};
