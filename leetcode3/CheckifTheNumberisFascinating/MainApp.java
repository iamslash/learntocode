// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 40.1MB 50.00%
// hash set
// O(N) O(1)
class Solution {
    private boolean updateSet(Set<Integer> numSet, int num) {
        System.out.println(num);
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            if (numSet.contains(digit)) {
                return false;
            }
            numSet.add(digit);
        }
        return true;
    }
    public boolean isFascinating(int n) {
        Set<Integer> numSet = new HashSet<>();
        if (!updateSet(numSet, n) ||
            !updateSet(numSet, 2 * n) ||
            !updateSet(numSet, 3 * n)) {
            return false;
        };
        return numSet.size() == 9 && numSet.contains(0) == false;
    }
}
