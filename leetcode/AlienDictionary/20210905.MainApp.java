// Copyright (C) 2021 by iamslash

import java.util.*;

// wrt
// wrf
// er
// ett
// rftt

// w e r t f

// 6ms 25.82% 39.1MB 42.70%
// topological sort with stack
// O(N^2) O(N^2)
class Solution {
    private StringBuilder order = new StringBuilder();
    private boolean adj[][] = new boolean[26][26];
    private boolean seen[] = new boolean[26];
    private void dumpAdj() {
        for (int u = 0; u < 26; ++u) {
            for (int v = 0; v < 26; ++v) {
                if (adj[u][v] == true) {
                    System.out.printf("%02d : %02d\n", u, v);
                }
            }
        }
    }
    private void dfs(int u) {
        seen[u] = true;
        for (int v = 0; v < 26; ++v) {
            if (adj[u][v] == true && seen[v] == false) {
                dfs(v);
            }
        }
        order.append((char)(u+'a'));
    }
    public String alienOrder(String[] words) {
        if (words.length == 0) {
            return "";
        }
        // build nodeSet
        Set<Character> nodeSet = new HashSet<>();
        for (String word : words) {
            for (char c : word.toCharArray()) {
                nodeSet.add(c);
            }
        }
        // build adj
        for (int i = 1; i < words.length; ++i) {
            String prvWord = words[i-1];
            String curWord = words[i];
            if (prvWord.length() > curWord.length() &&
                prvWord.startsWith(curWord)) {
                return "";
            }
            for (int j = 0; j < prvWord.length() && j < curWord.length(); ++j) {
                if (prvWord.charAt(j) != curWord.charAt(j)) {
                    int u = prvWord.charAt(j)-'a';
                    int v = curWord.charAt(j)-'a';
                    adj[u][v] = true;
                    break;
                }
            }
        }
        dumpAdj();
        // dfs all
        for (char c : nodeSet) {
            if (seen[c-'a'] == false) {
                dfs(c-'a');
            }
        }
        // reverse
        String ans = order.reverse().toString();
        // System.out.println(ans);
        // check back edge
        for (int i = 0; i < ans.length(); ++i) {
            for (int j = i+1; j < ans.length(); ++j) {
                int u = ans.charAt(i)-'a';
                int v = ans.charAt(j)-'a';
                if (adj[v][u] == true) {
                    return "";
                }
            }
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
