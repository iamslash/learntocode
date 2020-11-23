// Copyright (C) 2020 by iamslash

// 140ms 75.76% 46.6MB 7.58%
// backtracking
// O(N!) O(N)
var isValid = function(visit, i, last) {
    if (visit[i]) {
        return false;
    }
    if (last == -1) {
        return true;
    }
    // knight moves or adjacent cells
    if ((i + last) % 2 == 1) {
        return true;
    }
    let mid = (i + last) / 2;
    if (mid == 4) {
        return visit[mid];
    }
    // moves not on same rows, columns
    if ((i % 3 != last % 3) && (parseInt(i / 3) != parseInt(last / 3))) {
        return true;
    }
    // vertical, horizontal moves with visited waypoints
    return visit[mid]
}
var dfs = function(visit, last, len) {
    // base
    if (len == 0) {
        return 1;
    }
    // recursion
    let cnt = 0;
    for (let i = 0; i < 9; ++i) {
        if (isValid(visit, i, last)) {
            visit[i] = true;
            cnt += dfs(visit, i, len - 1);
            visit[i] = false;
        }
    }
    return cnt;
}
var numberOfPatterns = function(m, n) {
    let ans = 0;
    let visit = new Array(9);
    for (let len = m; len <= n; ++len) {
        visit.fill(false);
        ans += dfs(visit, -1, len);
    }
    return ans;
};
