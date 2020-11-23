// Copyright (C) 2020 by iamslash

/**
 * @param {number} n
 * @return {number}
 */

// 72ms 83.48% 38.5MB 10.18%
// iterative dynamic programming
// O(N^2) O(N)
var numTrees = function(n) {
  let C = new Array(n+1);
  C.fill(0);
  C[0] = 1;
  C[1] = 1;
  for (let i = 2; i <= n; ++i) {
    for (let j = 1; j <= i; ++j) {
      C[i] += C[j-1] * C[i-j];
    }
  }
  return C[n];
};