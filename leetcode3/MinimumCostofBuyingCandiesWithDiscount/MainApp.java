// Copyright (C) 2022 by iamslash

import java.util.*;

// 4ms 25.01% 39.6MB 48.12%
// sort
// O(NlgN) O(1)
class Solution {
    private int skipSum(int[] cost, int beg) {
        int n = cost.length, sum = 0;
        for (int i = beg; i < n; i += 3) {
            sum += cost[i+1] + cost[i+2];            
        }
        return sum;
    }
    public int minimumCost(int[] cost) {
        int n = cost.length;
        if (n == 1) {
            return cost[0];
        }
        if (n == 2) {
            return cost[0] + cost[1];
        }
        Arrays.sort(cost);
        int beg = n % 3, partSum = 0;
        if (beg == 1) {
            partSum += cost[0];
        } else if (beg == 2) {
            partSum += cost[0] + cost[1];
        }
        // System.out.printf("%d %d %d\n", cost[0], cost[1], partSum);
        return partSum + skipSum(cost, beg);
    }
}

//         i
// cost: 1 2 3
//  ans: 5
//           i
// cost: 1 2 3 4
//  ans: 1 6
//
// cost: 1 2 3 4 5
//  ans: 1 2 9

// 2ms 87.59% 39.6MB 62.00%
// sort, skip index
// O(NlgN) O(1)
class Solution {
    public int minimumCost(int[] cost) {
        int n = cost.length;
        if (n == 1) {
            return cost[0];
        }
        if (n == 2) {
            return cost[0] + cost[1];
        }
        Arrays.sort(cost);
        int ans = 0;
        for (int i = n-1; i >= 0; i -= 2) {
            ans += cost[i];
            if (i-1 >= 0) {
                ans += cost[i-1];
                --i;
            }
        }
        return ans;
    }
}
