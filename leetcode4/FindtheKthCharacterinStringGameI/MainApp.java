// Copyright (C) 2024 by iamslash

import java.util.*;

// k: 5
// s: a        - 0001
//    ab       - 0010
//    abbc     - 0100
//    abbcbccd - 1000
//
// The answer is s[k-1].
// Update k = k - 1.
// Think k as a binary format.
// s[100] = 'b' = 'a' + 1 = s[00] + 1
// s[101] = 'c' = 'b' + 1 = s[01] + 1
// s[111] = 'd' = 'c' + 1 = s[11] + 1
//
// s[1xx] is generated from s[xx].
// s[1xx] = s[xx] + 1.
// s[k] = s[0] + bits_count(k)

// Difficult to understand.
// 0ms 100.00% 41.2MB 97.15%
// bit manipulation
// O(lgK) O(1)
class Solution {
    public char kthCharacter(int k) {
        return (char)('a' + Integer.bitCount(k - 1));
    }
}

// 4ms 60.54% 43.5MB 33.50%
// brute force
// O(K) O(K) 
class Solution {

    public char kthCharacter(int k) {
        String s = "a";

        while (s.length() < k) {
            StringBuilder sb = new StringBuilder();

            for (char c : s.toCharArray()) {
                if (c == 'z') {
                    sb.append('a');
                } else {
                    sb.append((char)(c + 1));
                }
            }

            s += sb.toString();
        }

        return s.charAt(k - 1);
    }
}
