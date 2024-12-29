// Copyright (C) 2024 by iamslash

import java.util.*;


// Idea: all cases
//
// aeven * beven * ceven
// aeven *  bodd *  codd
//  aodd *  bodd * ceven
//  aodd * beven *  codd 
//
// edge cases...
//
// aodd bodd codd
//      0 1
//      0 1
// xor) 1 0
//      1 0
//
// aeven beven codd
//      1 1      1 1
//      1 1      1 1
// xor) 0 1    1 0 0
//      0 1    1 0 0

// 11ms 69.23% 62.68MB 38.46%
// bit manipulation
// O(N) O(1)
class Solution {
    public long tripletCount(int[] a, int[] b, int[] c) {
        long aeven = 0, aodd = 0, beven = 0, bodd = 0, ceven = 0, codd = 0;

        for (int num : a) {
            if (Integer.bitCount(num) % 2 == 0) {
                aeven++;
            } else {
                aodd++;
            }
        }

        for (int num : b) {
            if (Integer.bitCount(num) % 2 == 0) {
                beven++;
            } else {
                bodd++;
            }
        }
        
        for (int num : c) {
            if (Integer.bitCount(num) % 2 == 0) {
                ceven++;
            } else {
                codd++;
            }
        }

        long cnt = aeven * beven * ceven;
        cnt += aeven * bodd * codd;
        cnt += aodd * beven * codd;
        cnt += aodd * bodd * ceven;

        return cnt;
    }
}
