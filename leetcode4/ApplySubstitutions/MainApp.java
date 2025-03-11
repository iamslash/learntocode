// Copyright (C) 2025 by iamslash

import java.util.*;

// Idea: dfs
//
// replacements: A,bce B,ace C,abc%B%
//         text: %A%_%B%_%C%
//               i
//
//               bce_%B%_%C%
//                   i
//
//               bce_ace_%C%
//                       i
//
//               bce_ace_abc%B%
//                          i
//
//               bce_ace_abcace
//                             i
//
// 8ms 100.00% 45.39MB 100.00%
// dfs
// O(N) O(N)
class Solution {
    private String dfs(Map<String, String> dict, String s) {
        int n = s.length();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) != '%') {
                sb.append(s.charAt(i));
            } else {
                String key = s.substring(i + 1, i + 2);
                String val = dict.get(key);
                sb.append(dfs(dict, val));
                i += 2;
            }
        }

        return sb.toString();
    }
    
    public String applySubstitutions(List<List<String>> replacements, String text) {
        int n = replacements.size();
        Map<String, String> dict = new HashMap<>();
        String[] keys = text.split("_");

        for (List<String> replacement : replacements) {
            String key = replacement.get(0), val = replacement.get(1);
            dict.put(key, val);
        }

        return dfs(dict, text);
    }
}
