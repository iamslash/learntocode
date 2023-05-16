// Copyright (C) 2023 by iamslash

// Idea: dfs
//
// Get keys from the given object. (Object.entries())
// Sort it.
// Get vals of keys from the each object in the array.

// arr:
// [
//   {"b": 1, "a": 2},
//   {"b": 3, "a": 4}
// ]

// 498ms 41.67% 97.4MB 66.67%
// dfs
const getKeyPaths = (obj: any): string[] => {
    const rst = [];
    Object.entries(obj).forEach(([key, val]) => {
        if (val && typeof val === "object") {
            for (const sub of getKeyPaths(val)) {
                rst.push(`${key}.${sub}`);
            }
        } else {
            rst.push(key);
        }
    });
    return rst;
};
const retrieveFromPath = (path: string, obj: any): any => {
    const parsedPath = path.split(".");
    let i = 0, len = parsedPath.length;
    while (i < len && obj && typeof obj == 'object') {
        obj = obj[parsedPath[i++]];
    }
    if (i < len || obj !== null && typeof obj === 'object') {
        return undefined;
    }
    return obj;
};
const jsonToMatrix = (arr: any[]): (string | number | boolean | null)[] => {
    const rst = [], header = [];
    const visit = new Set();
    arr.forEach(obj => {
        const keys = getKeyPaths(obj);
        for (const key of keys) {
            if (visit.has(key)) {
                continue;
            }
            header.push(key);
            visit.add(key);
        }
    });
    header.sort();
    rst.push(header);
    for (const row of arr) {
        const tgtRow = [];
        for (const path of header) {
            const tgtObj = retrieveFromPath(path, row);
            if (tgtObj !== undefined) {
                tgtRow.push(tgtObj);
            } else {
                tgtRow.push("");
            }
        }
        rst.push(tgtRow);
    }
    return rst;
};

// 296ms 100.00% 95MB 83.33%
type Value = string | number | boolean | null;
function jsonToMatrix(arr: any[]): [string[], ...Value[][]] {
    const pathMaps: Map<string, Value>[] = [];
    const keySet = new Set<string>();

    const buildMap = (item: any, map: Map<string, Value>, prefix?: string): void => {
        prefix &&= prefix + '.';
        prefix ||= '';
        for (let key in item) {
            if (typeof item[key] === 'object' && item[key] !== null) {
                buildMap(item[key], map, prefix + key);
            } else {
                map.set(prefix + key, item[key]);
            }
        }
    };

    for (let i in arr) {
        pathMaps[i] = new Map<string, Value>();
        buildMap(arr[i], pathMaps[i]);
        for (let k of pathMaps[i].keys()) {
            keySet.add(k);
        }
    }

    const rst: [string[], ...Value[][]] = [[...keySet].sort()];

    pathMaps.forEach((map) => {
        const a: Value[] = [];
        for (let key of rst[0]) {
            a.push(map.get(key) === undefined ? '' : map.get(key)!);
        }
        rst.push(a);
    });

    return rst;
};
