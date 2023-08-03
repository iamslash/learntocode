// Copyright (C) 2023 by iamslash

// 48ms 100.00% 41.4MB 100.00%
function* factorial(n) {
    if (n === 0) {
        return 1;
    }
    var i = 1, prod = 1;
    while (i <= n) {
        prod = prod * i;
        i++;
        yield prod;
    }
};
