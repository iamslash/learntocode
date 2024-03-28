// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea:
//
// commonBits(num): return the number of bits where both n and num
// have the same value in that position of their binary
// representation.
//
//             n: 0101
//                0000
// commonBits(0): 2
//             n: 0101
//                0001
// commonBits(1): 3
//             n: 0101
//                0010
// commonBits(2): 1
//             n: 0101
//                0100
// commonBits(4): 3
//             n: 0101
//                1000
// commonBits(8): 1
//
//           ans: 0101 

// 7ms 100.00% 41.5MB 100.00%
public class Solution extends Problem {
    public int findNumber() {
        int ans = 0;

        for (int i = 0; i <= 30; ++i) {
            int bm = 1 << i;
            int zeroBits = commonBits(0);
            if (zeroBits < commonBits(bm)) {
                ans |= bm;
            }
        }

        return ans;
    }
}
