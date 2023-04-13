// Copyright (C) 2023 by iamslash

// 45ms 100.00% 43MB 100.00%
// O(N) O(1)
function createCounter(n: number): () => number {
    let cnt = n;
    return function() {
        return cnt++;
    }
}
