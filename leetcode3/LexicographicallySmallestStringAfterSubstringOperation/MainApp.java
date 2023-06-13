// Copyright (C) 2023 by iamslash

import java.util.*;


// Idea: edge cases
//
// We should do operation once exactly.  From first not `a` to the
// position next character is `a`.
//
// s: aaaaa
//    aaaaz
// s: aaaaaba
//    aaaaaaa

//    i
// s: c b a b c
//

// 21ms 81.49% 48.7MB 33.33%
// two pointers
// O(N) O(N)
class Solution {
    public String smallestString(String s) {
        char[] chars = s.toCharArray();
        int i = 0, n = s.length();
        while (i < n && chars[i] == 'a') {
            i++;
        }
        if (i == n) {
            chars[n-1] = 'z';
        }
        while (i < n && chars[i] != 'a') {
            chars[i] = (char)(chars[i] - 1);
            i++;
        }
        return String.valueOf(chars);
    }
}
