// Copyright (C) 2025 by iamslash

import java.util.*;

// digits: 0 2 2
//         2 2 0
//         2 0 2

// i
// 1 2 3 4
//     j
//   k

// 1 2 4
//
 
// 2ms 100.00% 43.49MB 100.00%
// brute force
// O(1) O(1)
class Solution {
    public int totalNumbers(int[] digits) {
        int cnt = 0, n = digits.length;
        int[] used1st = new int[10];

        for (int i = 0; i < n; ++i) {
            if (digits[i] == 0 || used1st[digits[i]] > 0) {
                continue;
            }
            used1st[digits[i]]++;
            
            int[] used2nd = new int[10];            
            for (int j = 0; j < n; ++j) {
                if (i == j || used2nd[digits[j]] > 0) {
                    continue;
                }
                used2nd[digits[j]]++;
                
                int[] used3rd = new int[10];                
                for (int k = 0; k < n; ++k) {
                    if (i == k || j == k ||
                        digits[k] % 2 > 0 ||
                        used3rd[digits[k]] > 0) {
                        continue;
                    }
                    used3rd[digits[k]]++;                    
                    cnt++;
                }
            }
        }

        return cnt;
    }
}
