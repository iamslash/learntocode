// Copyright (C) 2025 by iamslash

import java.util.*;

//         i
// lane1:  1 -2 -10 3
// lane2: -5 10   0 1

//        i
// lane1: 1 -1 -1  -1
// lane2: 0  3  4  -5

// Idea: Iterative Dynamic Programming
//
// maxCoinLane1
// Since Mario enters the freeway in lane1, maxCoinLane1 represents
// the maximum coins collected by staying in lane1 without any lane
// switches.  It is updated each mile as: maxCoinLane1 = Math.max(0,
// maxCoinLane1) + lane1[i].  Here, Math.max(0, maxCoinLane1) implies
// that if the previous total is negative, we can start fresh at the
// current mile.
//
// maxCoinLane2
// maxCoinLane2 represents the maximum coins after switching from
// lane1 to lane2 (i.e., after one lane switch when Mario is in
// lane2).  It is updated as: maxCoinLane2 = Math.max(maxCoinLane1,
// Math.max(0, maxCoinLane2) + lane2[i]).  This chooses the greater
// value between switching to lane2 immediately or continuing in lane2
// if already there.
//
// maxCoinLane21
// maxCoinLane21 represents the maximum coins obtained after switching
// back to lane1 from lane2 (i.e., after the second lane switch).  It
// is updated as: maxCoinLane21 = Math.max(maxCoinLane2, maxCoinLane21
// + lane1[i]).  The first term corresponds to switching from lane2 to
// lane1 immediately (making the second switch at the current mile),
// while the second term represents continuing in lane1 after already
// having switched twice.
//
// 3ms 88.00% 60.54MB 92.00%
// Iterative Dynamic Programming
// O(N) O(1)
class Solution {
    public long maxCoins(int[] lane1, int[] lane2) {
        int n = lane1.length;
        long maxCoin = Integer.MIN_VALUE;
        long maxCoinLane1 = Integer.MIN_VALUE;
        long maxCoinLane2 = Integer.MIN_VALUE;
        long maxCoinLane21 = Integer.MIN_VALUE;
        
        for (int i = 0; i < n; ++i) {
            maxCoinLane1 = Math.max(0, maxCoinLane1) + lane1[i];
            maxCoinLane2 = Math.max(maxCoinLane1, Math.max(0, maxCoinLane2) + lane2[i]);
            maxCoinLane21 = Math.max(maxCoinLane2, maxCoinLane21 + lane1[i]);
            maxCoin = Math.max(maxCoin, Math.max(maxCoinLane1, maxCoinLane21));
        }

        return maxCoin;
    }
}
