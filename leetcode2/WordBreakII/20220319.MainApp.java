// Copyright (C) 2022 by iamslash

import java.util.*;

// 10ms 14.53% 42.6MB 25.55%
// recursive dynamic programming
class Solution {
    private List<String> dfs(
                             String s,
                             List<String> wordDict,
                             Map<String, LinkedList<String>> C) {
        // base
        LinkedList<String> ans = new LinkedList<String>();
        if (s.length() == 0) {
            ans.add("");
            return ans;
        }
        // memo
        if (C.containsKey(s)) {
            return C.get(s);
        }
        // recursion
        for (String word : wordDict) {
            if (s.startsWith(word)) {
                List<String> subList = dfs(s.substring(word.length()), wordDict, C);
                for (String sub : subList) {
                    ans.add(word + (sub.isEmpty() ? "" : " ") + sub);
                }
            }
        }
        C.put(s, ans);
        return ans;
    }
    public List<String> wordBreak(String s, List<String> wordDict) {
        return dfs(s, wordDict, new HashMap<String, LinkedList<String>>());
    }
}

// 1ms 97.15% 42.6MB 25.55%
// backtracking
class Solution {
    private String genStr(List<String> path) {
        StringBuilder sb = new StringBuilder();
        for (String s : path) {
            sb.append(s).append(" ");
        }
        return sb.deleteCharAt(sb.length()-1).toString();
    }
    private void dfs(String s, List<String> wordDict, List<String> ans,
                     List<String> path, int beg) {
        // base
        if (beg == s.length()) {
            ans.add(genStr(path));
            return;
        }
        // recursion
        for (int i = beg; i <= s.length(); ++i) {
            if (wordDict.contains(s.substring(beg, i))) {
                path.add(s.substring(beg, i));
                dfs(s, wordDict, ans, path, i);
                path.remove(path.size() - 1);
            }
        }
    }
    public List<String> wordBreak(String s, List<String> wordDict) {
        List<String> ans = new ArrayList<>();
        List<String> path = new ArrayList<>();
        dfs(s, wordDict, ans, path, 0);
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
