// Copyright (C) 2024 by iamslash

// 70ms 40.82% 52.5MB 44.90%
// forward
// O(N) O(1)
function possibleStringCount(word: string): number {
    let cnt: number = 1;
    let prevChar: string = '0';

    for (const c of word) {
        if (c === prevChar) {
            cnt++;
        }
        prevChar = c;
    }

    return cnt;
};
