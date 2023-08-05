// Copyright (C) 2023 by iamslash

import java.util.*;

// 0ms 100.00% 43.5MB 53.77%
// brute force
// O(N) O(1)
class Solution {
    public double calculateTax(int[][] brackets, int income) {
        double ans = 0.0;
        int prv = 0;
        for (int[] bracket : brackets) {
            int profit = Math.min(bracket[0], income) - prv;
            prv = bracket[0];
            double ratio = bracket[1] * 0.01;
            ans += profit * ratio;
            if (bracket[0] > income) {
                break;
            }
        }
        return ans;
    }
}
