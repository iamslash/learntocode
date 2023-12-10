// Copyright (C) 2023 by iamslash

import java.util.*;

//                i
//  s: a b c a a  b
//     1 2 3 5 8 10
//
// ps:

// 36ms 97.22% 55.5MB 72.22%
// partial sum
// O(N) O(N)
class Solution {
    public int[] sameEndSubstringCount(String s, int[][] queries) {
        int n = s.length(), m = queries.length;
        int[] freqs = new int[26];
        int[] ans = new int[queries.length];
        int[][] ps = new int[n + 1][26];

        for (int i = 0; i < n; ++i) {
            freqs[s.charAt(i) - 'a']++;
            System.arraycopy(freqs, 0, ps[i + 1], 0, 26);
        }

        for (int i = 0; i < m; ++i) {
            int beg = queries[i][0], end = queries[i][1];
            int cnt = 0;
            for (char c = 'a'; c <= 'z'; ++c) {
                // count of s[l..r] = count of s[0..r+1) - count of s[0..l)
                int freq = ps[end + 1][c - 'a'] - ps[beg][c - 'a'];
                // C(freq, 2) + freq = freq * (freq - 1) / 2 + freq
                //                   = freq * (freq + 1) / 2
                cnt += freq * (freq + 1) / 2;
            }
            ans[i] = cnt;
        }
        
        return ans;
    }
}
