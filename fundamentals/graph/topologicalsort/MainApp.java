// Copyright (C) 2024 by iamslash

import java.util.*;

// dfs
// O(V+E) O(V)
public class MainApp {

    static int N = 6;
    static List<List<Integer>> adj = new ArrayList<>();
    static boolean[] visited;
    static List<Integer> order = new ArrayList<>();

    public static void printList(List<Integer> list) {
        for (int i : list) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    // order: 
    public static void dfs(int u) {
        visited[u] = true;
        System.out.printf("{ %d\n", u);
        for (int v = 0; v < N; ++v) {
            if (adj.get(u).get(v) > 0 && !visited[v]) {
                dfs(v);
            }
        }
        order.add(u);
        System.out.printf("} %d\n", u);
    }

    public static void dfsAll() {
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    }

    public static List<Integer> topologicalSort() {
        dfsAll();
        Collections.reverse(order);

        // Check for invalid edge direction
        for (int u = 0; u < N - 1; ++u) {
            for (int v = u + 1; v < N; ++v) {
                if (adj.get(order.get(v)).get(order.get(u)) > 0) {
                    return new ArrayList<>();
                }
            }
        }

        return order;
    }

    public static void main(String[] args) {
        for (int i = 0; i < N; ++i) {
            adj.add(new ArrayList<>(Collections.nCopies(N, 0)));
        }

        visited = new boolean[N];
        Arrays.fill(visited, false);

        adj.get(5).set(2, 1);
        adj.get(5).set(0, 1);
        adj.get(4).set(0, 1);
        adj.get(4).set(1, 1);
        adj.get(2).set(3, 1);
        adj.get(3).set(1, 1);

        List<Integer> result = topologicalSort();
        printList(result);
    }
}

// kahn algorithm
// O(V + E) O(V)
class MainApp {
    private ArrayList<Integer>[] adj;
    private int[] indegree;

    // Constructor with the number of vertices
    public MainApp(int n) {
        adj = new ArrayList[n];
        indegree = new int[n];
        for (int u = 0; u < n; ++u) {
            adj[u] = new ArrayList<>();
        }
    }

    // Method to add an edge to the graph
    public void addEdge(int u, int v) {
        adj[u].add(v);
        indegree[v]++;
    }

    // Topological sort method
    public List<Integer> topologicalSort() {
        Queue<Integer> q = new LinkedList<>();
        List<Integer> ord = new ArrayList<>();

        // Add all nodes with in-degree 0 to the queue
        for (int i = 0; i < indegree.length; ++i) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }

        // Perform BFS to determine topological order
        while (!q.isEmpty()) {
            int u = q.poll();
            ord.add(u);
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.offer(v);
                }
            }
        }

        return ord;
    }

    // Main method example
    public static void main(String[] args) {
        MainApp g = new MainApp(6);
        g.addEdge(5, 2);
        g.addEdge(5, 0);
        g.addEdge(4, 0);
        g.addEdge(4, 1);
        g.addEdge(2, 3);
        g.addEdge(3, 1);

        List<Integer> result = g.topologicalSort();
        System.out.println(result);
    }
}
