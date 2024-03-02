// Copyright (C) 2024 by iamslash

/** 
 * Definition of commonSetBits API (defined in the parent class Problem).
 * int commonSetBits(int num);
 */

// 1ms 100.00% 41MB 47.37%
// bit manipulation
// O(1) O(1)
public class Solution extends Problem {
    public int findNumber() {
        int n = 0;

        for (int i = 0; i < 30; ++i) {
            int bm = 1 << i;
            if (commonSetBits(bm) > 0) {
                n += bm;
            }
        }
        
        return n;
    }
}
