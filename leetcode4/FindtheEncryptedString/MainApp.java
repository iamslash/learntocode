// Copyright (C) 2024 by iamslash

import java.util.*;

//  s: byd
// ss: bydbyd
//     

// 1ms 100.00% 42.6MB 54.23%
// brute force
// O(N) O(N)
class Solution {
    public String getEncryptedString(String s, int k) {
        int n = s.length();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n; ++i) {
            char c = s.charAt((i + k) % n);
            sb.append(c);
        }

        return sb.toString();
    }
}
