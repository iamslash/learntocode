// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: math
//
// The answer is 1.
//   rook and queen in same row
//   rook and queen in same col
//   bishop and queen in the same anti-diagonal
//   bishop and queen in the same diagonal
// Otherwise the answer is 2.
//
// (a, b): white rook
// (c, d): white bishop
// (e, f): black queen

// 0ms 100.00% 41.1MB 43.84%
// math
// O(1) O(1)
class Solution {
    public int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e || b == f) {
            // bishop between rook and queen
            if (a == e && a == c && ((d - b) * (d - f) < 0)) {
                return 2;
            }
            if (b == f && b == d && ((c - a) * (c - e) < 0)) {
                return 2;
            }
            return 1;
        }
        if (Math.abs(c - e) == Math.abs(d - f)) {
            // rook between bishop and queen
            if (Math.abs(c - a) == Math.abs(d - b) &&
                Math.abs(e - a) == Math.abs(f - b) &&
                ((b - f) * (b - d) < 0)) {
                return 2;
            }
            return 1;
        }
        return 2;
    }
}
