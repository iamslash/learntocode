// Copyright (C) 2022 by iamslash

import java.util.*;


//                 i
//         s: "catsanddog"
// wordDict : ["cat","cats","and","sand","dog"]

// 1ms 97.15% 41.1MB 61.40%
// backtracking
// O(2^N) O(N)
class Solution {
    private void dfs(String s, List<String> wordDict,
                             List<String> ans, List<String> cand, int beg) {
        // base
        if (beg == s.length()) {
            ans.add(String.join(" ", cand));
            return;
        }
        // recursion
        for (int i = beg; i <= s.length(); ++i) {
            String word = s.substring(beg, i);
            if (wordDict.contains(word)) {
                cand.add(word);
                dfs(s, wordDict, ans, cand, i);
                cand.remove(cand.size() - 1);
            }
        }
    }
    public List<String> wordBreak(String s, List<String> wordDict) {
        List<String> ans = new ArrayList<>();
        List<String> cand =  new ArrayList<>();
        dfs(s, wordDict, ans, cand, 0);
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
