// Copyright (C) 2023 by iamslash

import java.util.*;

// 263ms 100.00% 43.8MB 100.00%
// hash map
// O(N) O(N)
class Solution {
    public int countDivisibleSubstrings(String word) {
        Map<Character, Integer> map = new HashMap();

        map.put('a', 1);
        map.put('b', 1);
        
        map.put('c', 2);
        map.put('d', 2);
        map.put('e', 2);
        
        map.put('f', 3);
        map.put('g', 3);
        map.put('h', 3);

        map.put('i', 4);
        map.put('j', 4);
        map.put('k', 4);

        map.put('l', 5);
        map.put('m', 5);
        map.put('n', 5);

        map.put('o', 6);
        map.put('p', 6);
        map.put('q', 6);
        
        map.put('r', 7);
        map.put('s', 7);
        map.put('t', 7);

        map.put('u', 8);
        map.put('v', 8);
        map.put('w', 8);

        map.put('x', 9);
        map.put('y', 9);
        map.put('z', 9);

        int cnt = 0, n = word.length();
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                int len = j - i + 1;
                sum += map.get(word.charAt(j));
                if (sum % len == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
}
