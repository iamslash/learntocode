// Copyright (C) 2020 by iamslash

/**
 * @param {number[][]} dungeon
 * @return {number}
 */
// 104ms 19.10% 37.1MB 89.98%
// dynamic programming
// O(HW) O(HW)
var calculateMinimumHP = function(G) {
  let h = G.length, w = G[0].length;
  let C = new Array(h+1);
  for (let y = 0; y <= h; ++y) {
    C[y] = new Array(w+1).fill(Number.MAX_SAFE_INTEGER);
  }
  C[h][w-1] = 1;
  C[h-1][w] = 1;
  for (let y = h-1; y >= 0; --y) {
    for (let x = w-1; x >= 0; --x) {
      C[y][x] = Math.max(Math.min(C[y+1][x], C[y][x+1]) - G[y][x], 1);      
    }
  }  
  return C[0][0];
};
