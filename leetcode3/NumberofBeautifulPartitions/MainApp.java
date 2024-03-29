// Copyright (C) 2023 by iamslash

import java.util.*;


// Idea: recursive dynamic programming
//
// Declare cache C[idx][remained k]
// Design int dfs(int i, int k)
// Loop inside dfs
//   i: start index
//   j: end index
//
// ex)
// minLen: 2
//      k: 3
//                           i
//                 .         .
//      s: 2 3 5 4 2 1 8 5 1 3 1
//                             j              
//                             o
//
// dfs(0, 3) 
//   dfs(2, 2) 
//   dfs(3, 2): 0 
//   dfs(4, 2): 1
//     dfs(6, 1): 0
//     dfs(7, 1): 0
//     dfs(8, 1): 0
//     dfs(9, 1): 1
//   dfs(5, 2) 
//   dfs(6, 2) 
//   dfs(7, 2) 

// 693ms 45.31% 47.8MB 51.56%
// recursive dynamic programming
// O(N^2K) O(NK)
class Solution {
    private boolean isPrime(char c) {
        return c == '2' || c == '3' || c == '5' || c == '7';
    }
    private int dfs(String s, int minLen, int[][] C, int i, int k) {
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
            // aabbcc
            //  j
            for (int j = i + minLen - 1; j < n - minLen * (k - 1); ++j) {
                if (isPrime(s.charAt(j))) {
                    continue;
                }
                cnt = (cnt + dfs(s, minLen, C, j + 1, k - 1)) % mod;
            }
        }
        return C[i][k] = cnt;
    }
    public int beautifulPartitions(String s, int k, int minLength) {
        int n = s.length();
        if (!isPrime(s.charAt(0)) || isPrime(s.charAt(n-1))) {
            return 0;
        }
        int[][] C = new int[n][k + 1];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(C[i], -1);
        }
        return dfs(s, minLength, C, 0, k);
    }
}

// Idea: iterative dyanmic programming
//
// Declare cache C[idx][remained k]
// Init C[0][0] = 1
// Set value a which means remained k
// Set idx i which means start index of current partition
// Set idx u which means start index of previous partition
//
// minLen: 3
//         u
//      s: aaabbbccc
//            i

// 39ms 89.06% 47MB 81.25%
// iterative dynamic programming
// O(NK) O(NK)
class Solution {
    private boolean isPrime(char c) {
        return c == '2' || c == '3' || c == '5' || c == '7';
    }
    public int beautifulPartitions(String s, int k, int minLen) {
        int n = s.length(), mod = 1_000_000_007;
        if (!isPrime(s.charAt(0)) || isPrime(s.charAt(n - 1))) {
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
