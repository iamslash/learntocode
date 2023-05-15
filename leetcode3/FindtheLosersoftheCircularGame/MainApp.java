// Copyright (C) 2023 by iamslash

import java.util.*;

//   k: 2
//            p
//   num: 1 2 3 4 5
// visit: t t t f f

// 2ms 100.00% 42.7MB 66.67%
// brute force
// O(N) O(N)
class Solution {
    public int[] circularGameLosers(int n, int step) {
        boolean[] visit = new boolean[n];
        int i = 0, pos = 0;
        while (visit[pos % n] == false) {
            i++;
            visit[pos % n] = true;
            pos += i * step;
        }
        int[] ans = new int[n - i];
        for (int j = 0, k = 0; j < n; ++j) {
            if (visit[j] == false) {
                ans[k++] = j + 1;
            }
        }
        return ans;
    }
}
