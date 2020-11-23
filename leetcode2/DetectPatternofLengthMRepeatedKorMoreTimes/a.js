// Copyright (C) 2020 by iamslash

//   m: 1
//   k: 3
//   A: 1 2 4 4 4 4
//              i
// cnt: 3

// linear traversal
// O(N) O(1)
var containsPattern = function(A, m, k) {
  let n = A.length;
  let cnt = 0;
  for (let i = 0; i + m < n; ++i) {
    if (A[i] == A[i+m]) {
      cnt++;
    } else {
      cnt = 0;
    }
    if (cnt == (k-1)*m) {
      return true;
    }
  }
  return false;
}
  