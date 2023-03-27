// Copyright (C) 2023 by iamslash

import java.util.*;

// k: 2
// 1 1 1 0 0
//

//    k: 4
// nums: 1 1 1 0 0
//

//    k: 6
// nums: 1 1 1 0 0 - -

// 1ms 16.67% 40MB 16.67%
// greedy
// O(1) O(1)
class Solution {
    public int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        if (numOnes >= k) {
            return k;
        }
        ans += numOnes;
        k -= numOnes;
        if (numZeros >= k) {
            return ans;
        }
        k -= numZeros;
        if (numNegOnes >= k) {
            return ans - k;
        }
        ans -= numNegOnes;
        return ans;
    }
}
