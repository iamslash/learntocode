// Copyright (C) 2023 by iamslash

import java.util.*;

//             i
//       s1: abe
//       s2: bea
//             a  b  e
// evenCnts:   0  1 -1
//  oddCnts:   0 -1  1 

// 5ms 95.74% 44.5MB 86.24%
// brute force
// O(N) O(1)
class Solution {
    public boolean checkStrings(String s1, String s2) {
        int[] evenCnts = new int[26], oddCnts = new int[26];
        int n = s1.length();
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                evenCnts[s1.charAt(i) - 'a']++;
                evenCnts[s2.charAt(i) - 'a']--;
            } else {
                oddCnts[s1.charAt(i) - 'a']++;
                oddCnts[s2.charAt(i) - 'a']--;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (evenCnts[i] != 0 || oddCnts[i] != 0) {
                return false;
            }
        }
        return true;
    }
}
