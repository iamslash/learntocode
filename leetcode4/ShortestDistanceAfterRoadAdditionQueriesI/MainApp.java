// Copyright (C) 2025 by iamslash

import java.util.*;

// n: 5
// q: 2,4 0,2 0,4
//
//        
// graph: 4 2 4 4 5

// 184ms 24.22% 45.63MB 68.57%
// bfs
// O(NQ) O(N)
class Solution {
    
    private int bfs(int n, List<List<Integer>> graph) {
        Queue<Integer> q = new LinkedList<>();
        int[] distance = new int[n];
        Arrays.fill(distance, -1);

        q.add(0);
        distance[0] = 0;

        while (!q.isEmpty()) {
            int u = q.poll();

            for (int v : graph.get(u)) {
                if (distance[v] == -1) { 
                    distance[v] = distance[u] + 1;
                    q.add(v);
                }
            }
        }

        return distance[n - 1]; 
    }
    
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        int[] answer = new int[queries.length];
        List<List<Integer>> graph = new ArrayList<>();

        for (int u = 0; u < n; ++u) {
            graph.add(new ArrayList<>());
        }

        for (int u = 0; u < n - 1; ++u) {
            graph.get(u).add(u + 1);
        }

        for (int i = 0; i < queries.length; ++i) {
            int u = queries[i][0], v = queries[i][1];
            graph.get(u).add(v);
            answer[i] = bfs(n, graph);
        }

        return answer;
    }
}

// iterative dynamic programming
// O(NQ) O(N)
class Solution {
    
    private int iterativeDP(int n, List<List<Integer>> graph) {
        int[] C = new int[n];
        Arrays.fill(C, Integer.MAX_VALUE);
        C[0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int u = 0; u < n; ++u) {
                if (C[u] == Integer.MAX_VALUE) {
                    continue;
                }
                for (int v : graph.get(u)) {
                    C[v] = Math.min(C[v], C[u] + 1);
                }
            }
        }

        return C[n - 1];        
    }
    
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        int[] answer = new int[queries.length];
        List<List<Integer>> graph = new ArrayList<>();

        for (int u = 0; u < n; ++u) {
            graph.add(new ArrayList<>());
        }

        for (int u = 0; u < n - 1; ++u) {
            graph.get(u).add(u + 1);
        }

        for (int i = 0; i < queries.length; ++i) {
            int u = queries[i][0], v = queries[i][1];
            graph.get(u).add(v);
            answer[i] = iterativeDP(n, graph);
        }

        return answer;
    }
}



// 15ms 70.08% 45.45MB 92.10%
// DFS
// O(N) O(N)
class Solution {

    private void dfs(List<List<Integer>> graph, int[] visited, int u){
        for(Integer v : graph.get(u)){
            if(visited[u] + 1 < visited[v]){
                visited[v] = visited[u] + 1;
                dfs(graph, visited, v);
            }
        }
    }

    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        int[] ans = new int[queries.length];
        int[] visited = new int[n];
        List<List<Integer>> graph = new ArrayList<>();
        
        for(int i = 0; i < n; ++i){
            graph.add(new ArrayList<>());
            if (i != n - 1) {
                graph.get(i).add(i + 1);
            }
            visited[i] = i;
        }
        
        for(int i = 0; i < queries.length; ++i) {
            int[] q = queries[i];
            graph.get(q[0]).add(q[1]);
            dfs(graph, visited, q[0]);
            ans[i] = visited[n - 1];
        }
        
        return ans;
    }
    
}
