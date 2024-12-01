// Copyright (C) 2024 by iamslash

import java.util.*;

//   n: 5
// ans: 1 11 111

// 0ms 100.005 40.9MB 100.00%
// bit manipulation
// O(lg10N) O(1)
class Solution {
    public int smallestNumber(int n) {

        int ans = 1;

        while (ans < n) {
            ans = ans * 2 + 1;
        }

        return ans;        
    }
}
