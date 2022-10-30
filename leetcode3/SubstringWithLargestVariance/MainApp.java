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

//           i
//      s:   a a b a b b b
//           
//   diff: a a
//         a b
//         0
//   temp: a
//         a
//         0

// 49ms 95.46% 43.8MB 40.62%
// iterative dynamic programming
// O(N) O(1)
// difficult
class Solution {
    public int largestVariance(String s) {
        int maxVar = 0, n = s.length();
        // freq of a
        int[][] freq = new int[26][26];
        // max(freqa - freqb)
        int[][] diff = new int[26][26];
        for (int i = 0; i < 26; ++i) {
            Arrays.fill(diff[i], -n);
        }
        for (int pos = 0; pos < n; ++pos) {
            int i = s.charAt(pos) - 'a';
            for (int j = 0; j < 26; ++j) {
                freq[i][j]++;
                diff[i][j]++;
                diff[j][i] = --freq[j][i];
                freq[j][i] = Math.max(0, freq[j][i]);
                maxVar = Math.max(maxVar, Math.max(diff[i][j], diff[j][i]));
            }
        }
        return maxVar;
    }
}

//               i
//      s:   a a b a b b b
//           
//   C[0]: a b
//         b a
//         1 -
//   C[1]: a b
//         b a
//         - -

// 31ms 97.96% 45.9MB 34.28%
// iterative dynamic programming
// O(N) O(1)
// difficult
class Solution {
    public int largestVariance(String s) {                
        int maxVar = 0;
        // C[a][b][0] is the freq of a
        // C[a][b][1] is the max(freqa - freqb) in all substring, minmum is -1
        int[][][] C = new int[26][26][2];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                C[i][j][1] = -10000;
            }
        }

        for (char c : s.toCharArray()) {
            int i = c - 'a';
            for (int j = 0; j < 26; j++) {
                if (i != j) {
                    // current ch freq + 1
                    C[i][j][0] += 1;
                    C[i][j][1] += 1;

                    // update b&a situation
                    C[j][i][1] = C[j][i][0] - 1;
                    if (C[j][i][0] > 0)
                        C[j][i][0] -= 1;

                    maxVar = Math.max(C[j][i][1], maxVar);
                    maxVar = Math.max(C[i][j][1], maxVar);
                }
            }
        }
        return maxVar;
    }
}

//              p: b
//              q: a
//              s: a b b
//                     i
//           pCnt: 2
//           qCnt: 0
// canExtendPrevQ: t
//            ans: 0

// 326ms 45.22% 42.4MB 86.26%
class Solution {
    public int largestVariance(String s) {
        int n = s.length(), ans = 0;
        for (char p = 'a'; p <= 'z'; ++p) {
            for (char q = 'a'; q <= 'z'; ++q) {
                int pCnt = 0, qCnt = 0;
                boolean canExtendPrevQ = false;
                for (char c : s.toCharArray()) {
                    if (c == p) {
                        pCnt++;
                    }
                    if (c == q) {
                        qCnt++;
                    }
                    if (qCnt > 0) {
                        ans = Math.max(ans, pCnt - qCnt);
                    } else if (qCnt == 0 && canExtendPrevQ) {
                        ans = Math.max(ans, pCnt - 1);
                    }
                    if (qCnt > pCnt) {
                        pCnt = 0;
                        qCnt = 0;
                        canExtendPrevQ = true;
                    }
                }
            }
        }
        return ans;
    }
}

// kadane algorithm
// O(N) O(1)
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
                boolean hasA = false, hasB = false;
                int remainA = 0, remainB = 0, maxSubarray = 0;
                for (char c : s.toCharArray()) {
                    int k = c - 'a';
                    if (k != i && k != j) {
                        continue;
                    }
                    if (maxSubarray < 0 && remainA != 0 && remainB != 0) {
                        maxSubarray = 0;
                        hasA = false;
                        hasB = false;
                    }
                    if (k == i) {
                        maxSubarray += 1;
                        remainA -= 1;
                        hasA = true;
                    } else if (k == j) {
                        maxSubarray -= 1;
                        remainB -= 1;
                        hasB = true;
                    }
                    if (hasA && hasB) {
                        maxVar = Math.max(maxVar, maxSubarray);
                    }
                }
            }
        }
        return maxVar;
    }
}
