// Copyright (C) 2020 by iamslash

//   s: a b c
//            i
//   t: a b c b c
//                j
// ans: 1

// 84ms 31.28% 39MB 9.48%
// greedy algorithm
// O(T) O(1)
var shortestWay = function(src, dst) {
    let i = 0, j = 0, ans = 0, m = src.length, n = dst.length;
    while (j < n && ans <= j) {
        while (src[i] != dst[j] && i < m) {
            ++i;
        }
        if (i == m) {
            i = 0;
            ++ans;
        } else {
            ++i;
            ++j;
        }
    }
    if (ans > j) {
        return -1
    }
    return ans + 1;
};
