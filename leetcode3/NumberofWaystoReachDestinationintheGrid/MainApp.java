// Copyright (C) 2023 by iamslash

import java.util.*;


// Idea:

// Can move when just same y, just same x case.
//
// a: same row
// b: same col
// o: other row, col
//
// o       b
//         b
// a a a a s a a
//         b
//         b
//         b
//
// number of cells
// a: w - 1
// b: h - 1
// o: same row of o can move to o. w - 2 (except o, b)
//    same col of o can move to o. h - 2 (except o, a)
// a, b can move to src.

// greedy
class Solution {
    public int numberOfWays(int h, int w, int k,
                            int[] src, int[] dst) {
        long mod = 1_000_000_007L;
        long center = 1, sameRow = 0, sameCol = 0, otherRowCol = 0;
        while (k-- > 0) {
            long prevCenter = center;
            long prevSameRow = sameRow;
            long prevSameCol = sameCol;
            long prevOtherRowCol = otherRowCol;
            center = (prevSameRow * (w - 1) +
                      prevSameCol * (h - 1)) % mod;
            sameRow = (prevSameRow * (w - 2) +
                       prevCenter +
                       prevOtherRowCol * (h - 1)) % mod;
            sameCol = (prevSameCol * (h - 2) +
                       prevCenter +
                       prevOtherRowCol * (w - 1)) % mod;
            otherRowCol = (prevOtherRowCol * (w - 2) +
                           prevOtherRowCol * (h - 2) +
                           prevSameRow + prevSameCol) % mod;
        }
        if (src[0] == dst[0] && src[1] == dst[1]) {
            return center;
        }
        if (src[0] == dst[0]) {
            return sameRow;
        }
        if (src[1] == dst[1]) {
            return sameCol;
        }
        return otherRowCol;
    }
}
