// Copyright (C) 2023 by iamslash

import java.util.*;

// n4ms 95.37% 82.8MB 78.84%
// partial sum
// O(N) O(N)
class Solution {
    private boolean startsEndsWithVowel(String s) {
        int n = s.length();
        char start = s.charAt(0), end = s.charAt(n - 1);
        if (start != 'a' && start != 'e' && start != 'i' && start != 'o' && start != 'u') {
            return false;
        }
        if (end != 'a' && end != 'e' && end != 'i' && end != 'o' && end != 'u') {
            return false;
        }
        return true;
    }
    public int[] vowelStrings(String[] words, int[][] queries) {
        int n = words.length, m = queries.length;
        int[] ps = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            if (startsEndsWithVowel(words[i])) {
                ps[i + 1]++;
            }
            ps[i + 1] += ps[i];
        }
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int s = queries[i][0], e = queries[i][1];
            ans[i] = ps[e + 1] - ps[s];
        }
        return ans;
    }
}
