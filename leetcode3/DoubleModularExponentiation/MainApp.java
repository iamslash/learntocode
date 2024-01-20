// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 44.2MB 38.69%
// brute force
// O(N) O(N)
class Solution {
    private int pow(int a, int b, int m) {
        int rst = 1;
        while (b > 0) {
            if ((b & 1) != 0) {
                rst = (rst * a) % m;
            }
            b >>= 1;
            a = (a * a) % m;
        }
        return rst;
    }
    public List<Integer> getGoodIndices(int[][] variables, int target) {
        int n = variables.length;
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            int[] vars = variables[i];
            int tmp = pow(vars[0], vars[1], 10);
            if (pow(tmp, vars[2], vars[3]) == target) {
                ans.add(i);
            }
        }
        return ans;
    }
}
