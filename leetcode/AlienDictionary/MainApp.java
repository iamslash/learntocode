// Copyright (C) 2022 by iamslash

import java.util.*;

// topological sort, queue
// O(N) O(N)
class Solution {
    public String alienOrder(String[] words) {
        boolean[][] G = new boolean[26][26];
        StringBuilder order = new StringBuilder();
        Map<Integer, Integer> indegMap = new HashMap<>();
        Queue<Integer> q = new LinkedList<>();
        int n = words.length;
        // Build Graph
        for (int i = 0; i < n-1; ++i) {
            char[] prvWord = words[i].toCharArray();
            char[] curWord = words[i+1].toCharArray();
            for (int j = 0; j < prvWord.length && j < curWord.length; ++j) {
                int u = prvWord[j] - 'a', v = curWord[j] - 'a';
                if (u != v) {
                    G[u][v] = true;
                    indegMap.putIfAbsent(u, 0);
                    indegMap.putIfAbsent(v, 0);
                    indegMap.put(v, indegMap.get(v) + 1);
                }
            }
        }
        // Build Queue
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
        return order.toString();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
