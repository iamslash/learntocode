// Copyright (C) 2022 by iamslash

import java.util.*;

//                       k
//      s:   a a b a b b b
//   hasB: f f f t t t t
// firstB: f f f f f f f
//    var: 0 1 2 1 2 1 0
// maxVar: 0 
//    i j
// f: a b
//    3 4
// remainI: 0
// remainJ: 4
//    cntI: 3
//    cntJ: 1
//  maxVar: 0

// 208ms 88.37% 90MB 30.51%
// kadane algorithm
// O(N) O(N)
// difficult
class Solution {
    public int largestVariance(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
        int maxVar = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (i == j || freq[i] == 0 || freq[j] == 0) {
                    continue;
                }
                int var = 0;
                boolean hasB = false, firstB = false;
                for (char c : s.toCharArray()) {
                    int k = c - 'a';
                    if (k == i) {
                        var++;
                    }
                    if (k == j) {
                        hasB = true;
                        if (firstB && var >= 0) {
                            firstB = false;
                        } else if (--var < 0) {
                            firstB = true;
                            var = -1;
                        }
                    }
                    maxVar = Math.max(maxVar, hasB ? var : 0);
                }
            }
        }
        return maxVar;
    }
}

// 49ms 95.46% 43.8MB 40.62%
// iterative dynamic programmingz
// O(N) O(1)
class Solution {
    public int largestVariance(String s) {
        int maxVar = 0, n = s.length();
        int[][] diff = new int[26][26];
        int[][] temp = new int[26][26];
        for (int i = 0; i < 26; ++i) {
            Arrays.fill(temp[i], -n);
        }
        for (int i = 0; i < n; ++i) {
            int idx = s.charAt(i) - 'a';
            for (int j = 0; j < 26; ++j) {
                diff[idx][j]++;
                temp[idx][j]++;
                temp[j][idx] = --diff[j][idx];
                diff[j][idx] = Math.max(0, diff[j][idx]);
                maxVar = Math.max(maxVar, Math.max(temp[idx][j], temp[j][idx]));
            }
        }
        return maxVar;
    }
}
