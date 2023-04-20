// Copyright (C) 2023 by iamslash

// 107ms 32.23% 69MB 12.40%
function jsonStringify(obj: any): string {
    // base
    if (typeof obj === 'number' || typeof obj === 'boolean' || obj === undefined) {
        return obj;
    }
    if (obj === null) {
        return 'null';
    }
    if (typeof obj === 'string') {
        return `"${obj}"`;
    }
    // recursion
    if (Array.isArray(obj)) {
        return `[${obj.map(jsonStringify).join(',')}]`;
    }
    return '{' + Object.keys(obj).map(key => `"${key}":${jsonStringify(obj[key])}`) + '}';
};
