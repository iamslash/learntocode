// Copyright (C) 2023 by iamslash

import java.util.*;

// primes: 2 3 5 7

//               i
//      s: 23542185131
//

// Idea: recursive dynamic programming
//
// Declare cache C[index][remained k]
// Design int dfs(int i, int k)
// i stands for start index
// j stands for end index
//
// minLen : 2
//       k: 3
//                  i          
// s: 2 3 5 4 2 1 8 5 1 3 1
//                      j 
// dfs(3, 0) : 3
//   dfs(2, 4) : 2
//     dfs(1, 7) : 1
//       dfs(0, 9) : 0
//       dfs(0, 11) : 1 
//     dfs(1, 9) : 1
//       dfs(0, 11) : 1 hit
//   dfs(2, 7) : 1
//     dfs(1, 9) : 1 hit

// 649ms 39.38% 47.7MB 58.13%
// recursive dynamic programming
// O(N^2K) O(NK)
class Solution {
    private boolean isPrime(char c) {
        return c == '2' || c == '3' || c == '5' || c == '7';
    }
    private int dfs(int[][] C, String s, int minLen, int i, int k) {
        int mod = 1_000_000_007, n = s.length();
        // base
        if (i == n && k == 0) {
            return 1;
        }
        if (i >= n || k <= 0) {
            return 0;
        }
        // memo
        if (C[i][k] >= 0) {
            return C[i][k];
        }
        // recursion
        int cnt = 0;
        if (isPrime(s.charAt(i))) {
            // i
            // 00xxxxaa
            //   j
            // j - i + 1 >= minLen
            for (int j = i + minLen - 1; j < n - minLen * (k - 1); ++j) {
                if (isPrime(s.charAt(j))) {
                    continue;
                }
                cnt = (cnt + dfs(C, s, minLen, j + 1, k - 1)) % mod;
            }
        }
        return C[i][k] = cnt;
    }
    public int beautifulPartitions(String s, int k, int minLen) {
        int n = s.length();
        if (!isPrime(s.charAt(0)) || isPrime(s.charAt(n-1))) {
            return 0;
        }
        int[][] C = new int[n][k + 1];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(C[i], -1);
        }
        return dfs(C, s, minLen, 0, k);
    }
}

// Idea: iterative dynamic programming
//
// Declare cache C[index][remained k]
// Init C[0][0] = 1
// Set value a wihch means remained k.
// Set index i which means start index current partition.
// Set index u which means start index previous partition.
//
// minLen: 3
//         u  
//      s: ooopppxxx
//            i

// 39ms 80.63% 47.7MB 58.13%
// iterative dynamic programming
// O(NK) O(NK)
// difficult
class Solution {
    private boolean isPrime(char c) {
        return c == '2' || c == '3' || c == '5' || c == '7';
    }
    public int beautifulPartitions(String s, int k, int minLen) {
        int n = s.length(), mod = 1_000_000_007;
        if (!isPrime(s.charAt(0)) || isPrime(s.charAt(n-1))) {
            return 0;
        }
        int[][] C = new int[n + 1][k + 1];
        C[0][0] = 1;
        for (int a = 1; a <= k; ++a) {
            int cnt = 0;
            for (int i = a * minLen, u = (a - 1) * minLen; i <= n; ++i, ++u) {
                cnt = (cnt + C[u][a - 1]) % mod;
                if (!isPrime(s.charAt(i - 1)) && (i == n || isPrime(s.charAt(i)))) {
                    C[i][a] = cnt;
                }
            }
        }
        return C[n][k];
    }
}
