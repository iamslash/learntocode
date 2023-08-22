// Copyright (C) 2023 by iamslash

// 5ms 99.92% 44.3MB 91.61%
// two pointers
// O(N) O(1)
class Solution {
    public boolean canMakeSubsequence(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        int j = 0;
        for (int i = 0; i < n && j < m; ++i) {
            char a = s1.charAt(i), b = s2.charAt(j);
            if (a == b || a + 1 == b || a - 25 == b) {
                j++;
            }
            // System.out.printf("i: %d, j: %d\n", i, j);
        }
        return j == m;
    }
}
