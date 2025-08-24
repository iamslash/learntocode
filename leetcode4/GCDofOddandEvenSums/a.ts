// Copyright (C) 2025 by iamslash

// 0ms 100.00% 57.78MB 100.00%
// math
// O(1) O(1)
function gcd(a: number, b: number): number {
    // base
    if (b == 0) {
        return a;
    }
    // recursion
    return gcd(b, a % b);
}
function gcdOfOddEvenSums(n: number): number {
    const nn = n + n;
    const sum = nn * (nn + 1) / 2;
    const sumOdd = (sum - n) / 2;
    const sumEvn = sumOdd + n;

    return gcd(sumEvn, sumOdd);
};

function main() {
    console.log("Hello World");
}
