// Copyright (C) 2025 by iamslash

import java.util.*;

// 114ms 62.19% 155.92MB 57.92%
// bfs, hash set
// O(NM) O(N)
class Solution {
    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        Set<Integer> invalidMethods = new HashSet<>();
        invalidMethods.add(k);
        Queue<Integer> queue = new LinkedList<>();
        queue.add(k);
        
        // Construct the graph using an adjacency list.
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int[] invocation : invocations) {
            int caller = invocation[0];
            int callee = invocation[1];
            graph.computeIfAbsent(caller, x -> new ArrayList<>()).add(callee);
        }
        
        // Perform BFS starting from k to mark all reachable methods as invalid.
        while (!queue.isEmpty()) {
            int current = queue.poll();
            if (graph.containsKey(current)) {
                for (int next : graph.get(current)) {
                    if (!invalidMethods.contains(next)) {
                        invalidMethods.add(next);
                        queue.add(next);
                    }
                }
            }
        }
        
        // If any non-invalid method calls an invalid method,
        // return a full list of methods.
        for (int[] invocation : invocations) {
            int caller = invocation[0];
            int callee = invocation[1];
            if (!invalidMethods.contains(caller) &&
                invalidMethods.contains(callee)) {
                return createFullList(n);
            }
        }
        
        // Otherwise, collect and return the methods that are not marked as invalid.
        List<Integer> remainedList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (!invalidMethods.contains(i)) {
                remainedList.add(i);
            }
        }
        
        return remainedList;
    }
    
    // Helper method to create a list of all methods from 0 to n-1.
    private List<Integer> createFullList(int n) {
        List<Integer> fullList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            fullList.add(i);
        }
        return fullList;
    }
}
