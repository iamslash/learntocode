// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea:
//              i
// people: 1 2 3 4
//           1 2 3
//         6 5 4
//           7 8 9
//
//   time: time % (n * 2 - 2)
//         time > n - 1

// 0ms 100.00% 39MB 100.00%
// math
// O(1) O(1)
class Solution {
    public int passThePillow(int n, int time) {
        time = time % (n * 2 - 2);
        if (time <= n - 1) {
            return time + 1;
        }
        return 2 * n - time - 1;
        // return n - (time - (n - 1));
    }
}

// Idea:
//               i    round
// people: 1 2 3 4
//           1 2 3    0
//         6 5 4      1
//           7 8 9    2

// 0ms 100.00% 39.8MB 100.00%
// math
// O(1) O(1)
class Solution {
    public int passThePillow(int n, int time) {
        // The number of traversing
        int round = time / (n - 1);
        // Last round index from left or right
        int i = time % (n - 1);
        // idx is from left
        if (round % 2 == 0) {
            return i + 1;
        }
        // idx is from right
        return n - i;
    }
}
