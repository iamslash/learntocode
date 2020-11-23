// Copyright (C) 2020 by iamslash

console.log("Hello World")

/**
 * @param {string} source
 * @param {string} target
 * @return {number}
 */

// 76ms 94.23% 38.8MB 69.23%
// two pointers
// O(ST) O(1)
var shortestWay = function(s, t) {
    let i = 0, j = 0, ans = 0;
    while (j < t.length && ans <= j) {
        if (i < s.length) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        } else {
            i = 0;
            ans++;
        }
    }
    if (++ans > j)
        return -1;
    return ans;
};
