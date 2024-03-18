// Copyright (C) 2024 by iamslash

import java.util.*;

// 2ms 54.93% 42.8MB 37.38%
// hash set
// O(N) O(N)
class Solution {
    public boolean isSubstringPresent(String s) {
        int n = s.length();
        Set<Integer> strSet = new HashSet<>();

        for (int i = 0; i < n - 1; ++i) {
            int a = s.charAt(i) - 'a', b = s.charAt(i + 1) - 'a';
            int key = a * 26 + b;
            strSet.add(key);
        }

        for (int i = n - 1; i > 0; --i) {
            int a = s.charAt(i) - 'a', b = s.charAt(i - 1) - 'a';
            int key = a * 26 + b;
            if (strSet.contains(key)) {
                return true;
            }
        }
        return false;
    }
}

// 1ms 99.83% 41.9MB 93.66%
// brute force
// O(N) O(1)
class Solution {
    public boolean isSubstringPresent(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        for(int i = 0; i < s.length() - 1; ++i){
            if(rev.contains(s.substring(i, i + 2))){
                return true;
            }
        }
        return false;
    }
}
