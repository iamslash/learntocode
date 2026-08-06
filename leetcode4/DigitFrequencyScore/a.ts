// Copyright (C) 2026 by iamslash

// 0ms 100.00% 58.48MB 27.44%
// math
// O(N) O(1)
function digitFrequencyScore(n: number): number {
    let ans: number = 0;

    while (n > 0) {
        ans += n % 10;
        n = Math.trunc(n / 10);
    }

    return ans;
};

function main() {
    console.log("Hello World");
}

main()
