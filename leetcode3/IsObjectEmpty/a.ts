// Copyright (C) 2023 by iamslash

// 68ms 100.00% 45.1MB 100.00%
function isEmpty(obj: Record<string, any> | any[]): boolean {
    if (Array.isArray(obj) === true) {
        return obj.length === 0;
    }
    if (typeof(obj) === 'object') {
        return Object.keys(obj).length === 0;
    }
    return false;
};
