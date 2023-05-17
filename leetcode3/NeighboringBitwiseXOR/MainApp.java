// Copyright (C) 2023 by iamslash

import java.util.*;

//  origin: a   b   c
// derived: 1   1   0
//          a^b b^c c^a

// 5ms 55.87% 52.4MB 15.93%
// math
// O(N) O(1)
class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        for (int i = 1; i < derived.length; ++i) {
            derived[0] ^= derived[i];
        }
        return derived[0] == 0;
    }
}
