"use strict";
// Copyright (C) 2026 by iamslash
// array
// O(HW) O(H)
function findDegrees(matrix) {
    const h = matrix.length;
    const w = matrix[0].length;
    const ans = new Array(h);
    for (let y = 0; y < h; ++y) {
        let cnt = 0;
        for (let x = 0; x < w; ++x) {
            cnt += matrix[y][x];
        }
        ans[y] = cnt;
    }
    return ans;
}
;
function main() {
    console.log("Hello World");
}
