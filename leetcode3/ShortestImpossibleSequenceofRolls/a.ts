// Copyright (C) 2022 by iamslash

// 116ms 100.00% 59.4MB 75.00%
// hash set
// O(N) O(K)
function shortestSequence(rolls: number[], k: number): number {
    let ans = 1;
    let diceSet = new Set<number>();
    for (var roll of rolls) {
        diceSet.add(roll);
        if (diceSet.size == k) {
            diceSet.clear();
            ans++;
        }
    }
    return ans;
};
