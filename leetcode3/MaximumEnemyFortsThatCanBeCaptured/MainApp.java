// Copyright (C) 2022 by iamslash

import java.util.*;


//               i
//  forts: 1 0 0 - 0 0 0 0 1
//               j

// Idea:
// The reslut is maximum forts

// 0ms 100.00% 40.4MB 25.60%
// two pointers
// O(N) O(1)
class Solution {
    public int captureForts(int[] forts) {
        int ans = 0, n = forts.length;
        for (int i = 0, j = 0; i < n; ++i) {
            if (forts[i] != 0) {
                if (forts[i] == -forts[j]) {
                    ans = Math.max(ans, i - j - 1);
                }
                j = i;
            }
        }
        return ans;
    }
}
