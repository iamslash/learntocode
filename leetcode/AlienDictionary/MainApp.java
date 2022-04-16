// Copyright (C) 2022 by iamslash

import java.util.*;

// 4ms 82.96% 40.5MB 96.62%
// topological sort, DFS
// O(N) O(N)
class Solution {
    private void dfs(boolean[][] graph, boolean[] visit, StringBuilder order, int u) {
        visit[u] = true;
        // recursion
        for (int v = 0; v < 26; ++v) {
            if (graph[u][v] && !visit[v]) {
                dfs(graph, visit, order, v);
            }
        }                
        order.append((char)(u + 'a'));
    }
    public String alienOrder(String[] words) {
        boolean[][] graph = new boolean[26][26];
        boolean[] visit = new boolean[26];
        StringBuilder order = new StringBuilder();
        // Build graph
        for (int i = 1; i < words.length; ++i) {
            String prvWord = words[i-1];
            String curWord = words[i];
            if (prvWord.length() > curWord.length() &&
                prvWord.startsWith(curWord)) {
                return "";
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
        // Build nodeSet
        Set<Integer> nodeSet = new HashSet<>();
        for (String word : words) {
            for (char c : word.toCharArray()) {
                nodeSet.add(c - 'a');
            }
        }
        // DFS all
        for (int u : nodeSet) {
            if (!visit[u]) {
                dfs(graph, visit, order, u);
            }
        }
        // Reverse
        String ans = order.reverse().toString();
        // Check back-endges
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

// 3ms 95.83% 40.4MB 96.62%
// topological sort, BFS
// O(N) O(N)
class Solution {
    public String alienOrder(String[] words) {
        boolean[][] graph = new boolean[26][26];
        Map<Integer, Integer> indegMap = new HashMap<>();
        StringBuilder order = new StringBuilder();
        int n = words.length;
        // Build indegMap
        for (String word : words) {
            for (char c : word.toCharArray()) {
                indegMap.put(c - 'a', 0);
            }
        }
        // Build Graph
        for (int i = 1; i < n; ++i) {
            String prvWord = words[i-1];
            String curWord = words[i];
            if (prvWord.length() > curWord.length() &&
                prvWord.startsWith(curWord)) {
                return "";
            }
            int minLen = Math.min(prvWord.length(), curWord.length());
            for (int j = 0; j < minLen; ++j) {
                int u = prvWord.charAt(j) - 'a';
                int v = curWord.charAt(j) - 'a';
                if (u != v) {
                    if (!graph[u][v]) {
                        graph[u][v] = true;
                        indegMap.put(v, indegMap.getOrDefault(v, 0) + 1);
                    }
                    break;
                }
            }
        }
        // Build q
        Queue<Integer> q = new LinkedList<>();
        for (Integer u : indegMap.keySet()) {
            if (indegMap.get(u) == 0) {
                q.offer(u);
            }
        }
        // BFS
        while (!q.isEmpty()) {
            int u = q.poll();
            order.append((char)(u + 'a'));
            for (int v = 0; v < 26; ++v) {
                if (graph[u][v]) {
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
