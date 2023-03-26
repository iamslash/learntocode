// Copyright (C) 2023 by iamslash

import java.util.*;

// // brute force
// // O(?) O(?)
// class Solution {
//     private boolean iskMirror(long k, long n) {
//         // original num, mirrored num
//         long org = n, mir = 0;
//         while (n > 0) {
//             mir = mir * k + n % k;
//             n /= k;
//         }
//         return org == mir;
//     }
//     public long kMirror(int k, int n) {
//         long ans = 0, cnt = 0;
//         for (long a = 1; a < Long.MAX_VALUE; ++a) {
//             if (iskMirror(k, a) && iskMirror(10, a)) {
//                 ans += a;
//                 cnt++;
//                 if (cnt == n) {
//                     return ans;
//                 }
//             }
//         }
//         return ans;
//     }
// }

// Idea: back tracking
//
// Generate palindrome nums based on k.
//   Check 10-based num is palindrome.

// 668ms 76.47% 42.1MB 64.71%
// back tracking
// O(?) O(?)
class Solution {
    private boolean palindrome(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) {
                return false;
            }
        }
        return true;
    }
    private void dfs(List<Long> numList, char[] chars, char k, int idx) {
        int n = chars.length;
        // base
        if (idx >= (n + 1) / 2) {
            String s = new String(chars);
            long num10 = Long.parseLong(s, k - '0');
            if (palindrome(Long.toString(num10))) {
                numList.add(num10);                
            }
            return;
        }
        // recursion
        for (char i = '0'; i < k; ++i) {
            if (idx == 0 && i == '0') {
                continue;
            }
            chars[idx] = i;
            chars[n - 1 - idx] = i;
            dfs(numList, chars, k, idx + 1);
             
        }
    }
    public long kMirror(int k, int n) {
        int len = 1;
        List<Long> numList = new ArrayList<>();
        while (numList.size() < n) {
            char[] chars = new char[len];
            dfs(numList, chars, (char)(k + '0'), 0);
            len++;
        }
        while (numList.size() > n) {
            numList.remove(numList.size() - 1);
        }
        long sum = 0;
        for (Long num : numList) {
            sum += num;
        }
        return sum;        
    }
}
