// Copyright (C) 2026 by iamslash

// 3ms 15.93% 58.68MB 5.31%
// linear traversal
// O(N) O(N)
function reversePrefix(s: string, k: number): string {
    let arr = s.split('');
    let h = Math.floor(k / 2);

    for (let i = 0; i < h; ++i) {
        [arr[i], arr[k - i - 1]] = [arr[k - i - 1], arr[i]];
    }

    return arr.join('');
};

function main() {
    console.log("Hello World");
}
