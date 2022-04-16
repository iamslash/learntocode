// Copyright (C) 2022 by iamslash

import java.util.*;

// 10ms 21.38% 41.6MB 88.19%
// topological sort, queue
// O(N) O(N)
class Solution {
    public String alienOrder(String[] words) {
        boolean[][] G = new boolean[26][26];
        Map<Integer, Integer> indegMap = new HashMap<>();
        StringBuilder order = new StringBuilder();
        int n = words.length;
        // Build indegMap
        for (String word : words) {
            for (char c : word.toCharArray()) {
                indegMap.put(c-'a', 0);
            }
        }
        // Build Graph
        for (int i = 0; i < n-1; ++i) {
            if (words[i].length() != words[i+1].length() &&
                words[i].startsWith(words[i+1])) {
                return "";
            }
            char[] prvWord = words[i].toCharArray();
            char[] curWord = words[i+1].toCharArray();
            int minLen = Math.min(prvWord.length, curWord.length);
            for (int j = 0; j < minLen; ++j) {
                int u = prvWord[j] - 'a', v = curWord[j] - 'a';
                if (u != v) {
                    if (G[u][v] == false) {
                        G[u][v] = true;
                        indegMap.put(v, indegMap.get(v) + 1);
                    }
                    break;
                }
            }            
        }
        // Build Queue
        Queue<Integer> q = new LinkedList<>();
        for (Integer u : indegMap.keySet()) {
            if (indegMap.get(u) == 0) {
                q.offer(u);
            }
        }
        // topological sort
        while (!q.isEmpty()) {
            int u = q.poll();
            order.append((char)('a' + u));
            for (int v = 0; v < 26; ++v) {
                if (G[u][v]) {
                    indegMap.put(v, indegMap.get(v) - 1);
                    if (indegMap.get(v) == 0) {
                        q.offer(v);
                    }
                }
            }
        }
        if (order.length() != indegMap.size()) {
            return "";
        }
        return order.toString();
    }
}

// 6ms 66.07% 42.4MB 69.93%
// topological sort, stack
// O(N) O(N)
class Solution {
    private StringBuilder order = new StringBuilder();
    private boolean[][] graph = new boolean[26][26];
    private boolean[] visit = new boolean[26];
    private void dumpAdj() {
        for (int u = 0; u < 26; ++u) {
            for (int v = 0; v < 26; ++v) {
                if (graph[u][v] == true) {
                    System.out.printf("%02d : %02d\n", u, v);
                }
            }
        }
    }    
    private void dfs(int u) {
        visit[u] = true;
        for (int v = 0; v < 26; ++v) {
            if (graph[u][v] && !visit[v]) {
                dfs(v);
            }
        }
        order.append((char)(u + 'a'));
    }
    public String alienOrder(String[] words) {
        Set<Integer> nodeSet = new HashSet<>();
        // Build nodeSet
        for (String word : words) {
            for (char c : word.toCharArray()) {
                nodeSet.add(c - 'a');
            }
        }
        // Build graph
        for (int i = 1; i < words.length; ++i) {
            String prvWord = words[i-1];
            String curWord = words[i];
            if (prvWord.length() > curWord.length() &&
                prvWord.startsWith(curWord)) {
                return"";
            }
            int minLen = Math.min(prvWord.length(), curWord.length());
            for (int j = 0; j < minLen; ++j) {
                int u = prvWord.charAt(j) - 'a';
                int v = curWord.charAt(j) - 'a';
                if (u != v) {
                    graph[u][v] = true;
                    break;
                }
            }
        }
        // dumpAdj();
        // dfs
        for (int u : nodeSet) {
            if (!visit[u]) {
                dfs(u);
            }
        }
        // Reverse
        String ans = order.reverse().toString();
        // Check back-edge
        for (int i = 0; i < ans.length(); ++i) {
            for (int j = i+1; j < ans.length(); ++j) {
                int u = ans.charAt(i) - 'a';
                int v = ans.charAt(j) - 'a';
                if (graph[v][u]) {
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
