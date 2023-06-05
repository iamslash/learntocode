// Copyright (C) 2023 by iamslash

import java.util.*;

// s: a a a a b b a b b c

// 9ms 100.00% 44.4MB 25.00%
// hash set
// O(N) O(1)
class Solution {
    public int minimizedStringLength(String s) {
        Set<Character> strSet = new HashSet<>();
        for (char c : s.toCharArray()) {
            strSet.add(c);
        }
        return strSet.size();
    }
}
