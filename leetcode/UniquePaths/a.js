// Copyright (C) 2020 by iamslash

// 92ms 10.85% 38.9MB 36.12%
// iterative dynamic programming
// O(HW) O(HW)
var uniquePaths = function(h, w) {
    let C = Array.from(Array(h), a => Array(w).fill(0));
    C[0][0] = 1;
    for (let y = 0; y < h; ++y) {
        for (let x = 0; x < w; ++x) {
            if (y > 0) {
                C[y][x] += C[y-1][x];
            }
            if (x > 0) {
                C[y][x] += C[y][x-1];
            }
        }
    }
    return C[h-1][w-1];    
};