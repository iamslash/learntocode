// Copyright (C) 2024 by iamslash

// 1ms 100.00% 44.4MB 87.65%
// math
// O(N) (1)
class Solution {
    public long countSubstrings(String s, char c) {
        long cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == c) {
                cnt++;
            }
        }
        return cnt * (cnt + 1) / 2; 
    }
}
