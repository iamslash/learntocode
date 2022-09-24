// Copyright (C) 2022 by iamslash

//     i
// s: _R
// t: R_
//    j

// 162ms 62.50%
// two pointers
// O(N) O(1)
function canChange(s: string, t: string): boolean {
    let i = 0, j = 0, n = s.length;
    while (i < n || j < n) {
        while (i < n && s.charAt(i) == '_') {
            i++;
        }
        while (j < n && t.charAt(j) == '_') {
            j++;
        }
        if (i == n ||
            j == n ||
            s.charAt(i) != t.charAt(j) ||
            (s.charAt(i) == 'L' && i < j) ||
            (s.charAt(i) == 'R' && i > j)) {
            break;
        }
        i++;
        j++;
    }
    return i == n && j == n;
};
