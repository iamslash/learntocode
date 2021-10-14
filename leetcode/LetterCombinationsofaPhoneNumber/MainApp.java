// Copyright (C) 2021 by iamslash

import java.util.*;

// // 4ms 44.30% 39.1MB 59.85%
// // back tracking
// // O(3^N) O(lg_3_N)
// class Solution {
//     private final char[][] chars = new char[][]{
//         {'a', 'b', 'c'},
//         {'d', 'e', 'f'},
//         {'g', 'h', 'i'},
//         {'j', 'k', 'l'},
//         {'m', 'n', 'o'},
//         {'p', 'q', 'r', 's'},
//         {'t', 'u', 'v'},
//         {'w', 'x', 'y', 'z'},
//     };
//     private List<String> ans = new ArrayList<>();
//     private void dfs(String digits, int idx, String cand) {
//         // base
//         if (idx >= digits.length()) {
//             ans.add(cand);
//             return;
//         }
//         // recursion
//         int j = (digits.charAt(idx) - '0') - 2;
//         for (char c : chars[j]) {
//             dfs(digits, idx + 1, cand + c);
//         }
//     }
//     public List<String> letterCombinations(String digits) {
//         if (digits.isEmpty()) {
//             return ans;
//         }
//         dfs(digits, 0, "");
//         return ans;
//     }
// }

// 0ms 100.00% 37.6MB 88.15%
// back tracking
// O(3^N) O(lg_3_N)
class Solution {
    private final char[][] chars = new char[][]{
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'},
    };
    private List<String> ans = new ArrayList<>();
    private void dfs(String digits, int idx, StringBuilder cand) {
        // base
        if (idx >= digits.length()) {
            ans.add(cand.toString());
            return;
        }
        // recursion
        int j = (digits.charAt(idx) - '0') - 2;
        for (char c : chars[j]) {
            cand.append(c);
            dfs(digits, idx + 1, cand);
            cand.deleteCharAt(cand.length()-1);
        }
    }
    public List<String> letterCombinations(String digits) {
        if (digits.isEmpty()) {
            return ans;
        }
        dfs(digits, 0, new StringBuilder());
        return ans;
    }
}


public class MainApp {
  public static void main(String[] args) {
  }
}
