// Copyright (C) 2024 by iamslash

// 55ms 91.67% 54.8MB 73.53%
// backtracking
// O(2^N) O(N)
function dfs(n: number, ans: string[], cand: string, last: number) {
    // base
    if (cand.length === n) {
        ans.push(cand);
        return;
    }

    // recursion
    dfs(n, ans, cand + '1', 1);
    if (last !== 0) {
        dfs(n, ans, cand + '0', 0);
    }
}

function validStrings(n: number): string[] {
    const ans: string[] = [];
    dfs(n, ans, '', -1);
    return ans;
};
