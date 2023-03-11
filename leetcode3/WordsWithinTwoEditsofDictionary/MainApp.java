// Copyright (C) 2023 by iamslash

import java.util.*;

// 2ms 95.02% 42.7MB 33.33%
// brute force
// O(QD) O(N)
class Solution {
    private int distance(String a, String b) {
        int n = a.length(), dist = 0;
        for (int i = 0; i < n; ++i) {
            if (a.charAt(i) != b.charAt(i)) {
                if (++dist > 2) {
                    break;
                }
            }
        }
        return dist;
    }
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        List<String> ans = new ArrayList<>();
        for (String query : queries) {
            for (String word : dictionary) {
                if (distance(query, word) <= 2) {
                    ans.add(query);
                    break;
                }
            }
        }
        return ans;
    }
}
