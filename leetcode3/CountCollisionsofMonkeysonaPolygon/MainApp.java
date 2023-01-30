// Copyright (C) 2023 by iamslash

import java.util.*;

// n: 3
//    0+ 1- 2+
//          2-
//    1+ 2- 0+
//          0-
//    2+ 1- 0+
//          0-

// n: 4
//    0+ 1- 2+ 3+
//             3- a
//          2- 3+
//             3-
//    1+ 2- 3+ 0+
//             0- b
//          3- 0+
//             0-
//    2+ 3- 0+ 1+
//             1- a
//          0- 1+
//             1-
//    3+ 0- 1+ 2+
//             2- b
//          1- 2+
//             2-

// Idea: math
//
// All cases are 2 ^ n.
// The number of collision is 2.
//   All move to left or All move to right.
// The answer is 2 ^ n - 2.

// // Wrong Answer
// // 63
// // 
// // math
// // O(lgN) O(1)
// class Solution {
//     public int monkeyMove(int n) {
//         long mod = 1_000_000_007L;
//         long ans = (long)Math.pow(2, n);
//         return (int)((ans - 2 + mod) % mod);
//     }
// }

// 0ms 100.00% 38.9MB 87.15%
// math
// O(lgN) O(1)
class Solution {
    public int monkeyMove(int n) {
        long ans = 1, base = 2, mod = 1_000_000_007L;
        while (n > 0) {
            if (n % 2 == 1) {
                ans = ans * base % mod;
            }
            base = base * base % mod;
            n >>= 1;
        }
        return (int)((ans - 2 + mod) % mod);
    }
}
