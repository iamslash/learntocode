// Copyright (C) 2022 by iamslash

import java.util.*;

// 125ms 33.33% 55.7MB 41.41%
// dynamic programming
// O(NAC) O(NAC)
// N: count of price
// A: maxAmount
// C: maxCoupons
class Solution {
    public int maxTastiness(int[] price, int[] tastiness,
                            int maxAmount, int maxCoupons) {
        int n = price.length;
        // maximum tastiness
        int[][][] C = new int[n + 1][maxAmount + 1][maxCoupons + 1];
        for (int i = 0; i < n; ++i) {
            for (int amt = 0; amt <= maxAmount; ++amt) {
                for (int cpn = 0; cpn <= maxCoupons; ++cpn) {
                    // don't buy
                    C[i+1][amt][cpn] = C[i][amt][cpn];
                    // buy
                    if (amt >= price[i]) {
                        C[i+1][amt][cpn] = Math.max(C[i+1][amt][cpn],
                                                    tastiness[i] +
                                                    C[i][amt - price[i]][cpn]);
                    }
                    // buy with coupon
                    if (cpn > 0 && amt >= price[i] / 2) {
                        C[i+1][amt][cpn] = Math.max(C[i+1][amt][cpn],
                                                    tastiness[i] +
                                                    C[i][amt - price[i]/2][cpn-1]);
                    }
                }
            }
        }
        return C[n][maxAmount][maxCoupons];
    }
}

// 17ms 100.00% 41.7MB 100.00%
// dynamic programming
// O(NAC) O(NAC)
// N: count of price
// A: maxAmount
// C: maxCoupons
class Solution {
    public int maxTastiness(int[] price, int[] tastiness,
                            int maxAmount, int maxCoupons) {
        int n = price.length;
        int[][] C = new int[maxAmount + 1][maxCoupons + 1];
        for (int[] line : C) {
            Arrays.fill(line, Integer.MIN_VALUE);
        }
        C[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int amt = maxAmount; amt >= 0; --amt) {
                for (int cpn = maxCoupons; cpn >= 0; cpn--) {
                    if (price[i] <= amt) {
                        C[amt][cpn] = Math.max(C[amt][cpn],
                                               tastiness[i] +
                                               C[amt - price[i]][cpn]);
                    }
                    if (cpn > 0 && amt >= price[i] / 2) {
                        C[amt][cpn] = Math.max(C[amt][cpn],
                                               tastiness[i] +
                                               C[amt - price[i]/2][cpn-1]);
                    }
                }
            }
        }
        int ans = 0;
        for (int amt = 0; amt <= maxAmount; ++amt) {
            for (int cpn = 0; cpn <= maxCoupons; ++cpn) {
                ans = Math.max(ans, C[amt][cpn]);
            }
        }
        return ans;
    }
}
