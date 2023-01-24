// Copyright (C) 2023 by iamslash

import java.util.*;

// s: 1 0 1 0
// t: 0 1 1 0
//
// i: 0 1 0 1 
// j: 0 0 1 1
//    0 1 1 1
//    0 1 1 0

// 1ms 98.98% 43.1MB 77.19%
// brute force
// O(N) O(1)
class Solution {
    public boolean makeStringsEqual(String s, String t) {
        return s.contains("1") == t.contains("1");
    }
}
