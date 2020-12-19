// Copyright (C) 2020 by iamslash

/**
 * @param {string} s
 * @return {number}
 */

// 96ms 34.60% 39.5MB 47.98%
// iterative dynamic programming
// O(N) O(1)
var numDecodings = function(s) {
  if (s.length === 0 || s[0] === '0')
    return 0;
  let n1 = 1, n2 = 0;
  for (let i = 1; i < s.length; ++i) {
    let m1 = 0, m2 = 0;
    if (s[i] >= '1' && s[i] <= '9') {
      m1 = n1 + n2;
    }
    let n = Number(s.substring(i-1,i+1))
    if (n >= 10 && n <= 26) {
      m2 = n1;
    }
    n1 = m1, n2 = m2;
  }
  return n1 + n2;
};