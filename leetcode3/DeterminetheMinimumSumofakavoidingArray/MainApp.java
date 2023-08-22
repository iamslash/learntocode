// Copyright (C) 2023 by iamslash

import java.util.*;

// n: 5
// k: 4
//                   i
// nums: 1 2 3 4 5 6 7
// 

// 5ms 41.13% 43.5MB 6.40%
// hash set
// O(N) O(N)
class Solution {
    public int minimumSum(int n, int k) {
        Set<Integer> numSet = new HashSet<>();
        int sum = 0, cnt = 0;
        for (int i = 1; numSet.size() < n; ++i) {
            if (numSet.contains(k - i)) {
                continue;
            }
            numSet.add(i);
            sum += i;
            cnt++;
        }
        // System.out.println(numSet);
        return sum;
    }
}

