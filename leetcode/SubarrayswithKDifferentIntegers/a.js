// Copyright (C) 2019 by iamslash

// 104ms 70.37% 40.7MB 100.00%
// hash map, sliding window
// O(N) O(N)
const subarraysWithKDistinct = (A, K) => {
  function cntWithMostK(A, K) {
    let ans = 0, n = A.length, cnt = new Map();
    for (let i = 0, j = 0; j < n; ++j) {
      if (!cnt[A[j]]) {
        cnt[A[j]] = 0;
        K--;
      }
      cnt[A[j]]++;
      while (K < 0) {
        if (!--cnt[A[i]]) {
          K++;
        }
        i++;
      }
      ans += j - i + 1;
    }
    return ans;
  }
  return cntWithMostK(A, K) - cntWithMostK(A, K-1);
}

let A = [1, 2, 1, 2, 3];
let K = 2;
console.log(subarraysWithKDistinct(A, K));