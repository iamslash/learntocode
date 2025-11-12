// Copyright (C) 2025 by iamslash

import java.util.*;

// 1ms 100.00% 44.82MB 5.88%
// back and forth
// O(N) O(1)
class Solution {
    public int maxDistance(String[] words) {
        int n = words.length;
        int maxDist = 0;

        if (n == 1) {
            return 0;
        }

        if (!words[0].equals(words[n-1])) {
            return n;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (!words[n-1].equals(words[i])) {
                maxDist = Math.max(maxDist, n - i);
                break;
            }
        }

        for (int i = n - 1; i > 0; --i) {
            if (!words[0].equals(words[i])) {
                maxDist = Math.max(maxDist, i + 1);
            }
        }

        return maxDist;        
    }
}
