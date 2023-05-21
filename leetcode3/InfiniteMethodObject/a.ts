// Copyright (C) 2023 by iamslash

// 58ms 100.00% 42.9MB 60.00%
function createInfiniteObject(): Record<string, () => string> {
    return new Proxy({}, {
        get(target, prop) {
            return () => prop;
        }
    });
};
