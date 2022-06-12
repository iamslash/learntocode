// Copyright (C) 2022 by iamslash

import java.util.*;


//   income: 10
// brackets: 3,50 7,10 12,25
//              i

// 1ms 88.89% 46.4MB 11.11%
// math
// O(N) O(1)
class Solution {
    public double calculateTax(int[][] brackets, int income) {
        double sum = 0.0;
        for (int i = 0; i < brackets.length; ++i) {
            double curUpper = Math.min(brackets[i][0], income);
            double prvUpper = i == 0 ? 0.0 : brackets[i-1][0];
            sum += (curUpper - prvUpper) * brackets[i][1];
            if (brackets[i][0] >= income) {
                break;
            }
        }
        return sum * 0.01;
    }
}
