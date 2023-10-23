/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

// 381ms 51.06% 167.9MB 91.33%
// bfs
// O(N) O(N)
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
      vector<vector<int>> graph(n);
      vector<int> cnts(n);
      int ans = 0;
      // Build graph
      for (const auto& edge : edges) {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
      }
      // Add leaf nodes
      queue<int> q;
      for (int u = 0; u < n; ++u) {
        cnts[u] = graph[u].size();
        // Add leaf node to queue
        if (cnts[u] < 2) {
          q.push(u);
        }
      }
      // BFS
      while (!q.empty()) {
        int u = q.front(); q.pop();
        --cnts[u];
        ans += values[u] % k == 0;
        for (auto v : graph[u]) {
          if (cnts[v] != 0) {
            values[v] += values[u] % k;
            // Add leaf node to queue
            if (--cnts[v] == 1) {
              q.push(v);
            }
          }
        }
      }
      return ans;
    }
};

// k: 6
//        8
//      /   \
//    1       4
//   / \
//  4   1

// 354ms 73.10% 170.9MB 84.14%
// dfs
// O(N) O(N)
class Solution {
private:
    int cnt;
    // Return cost of component
    int dfs(vector<int>& values, int k, vector<int> graph[], 
            vector<bool>& visit, int u) {
        visit[u] = true;
        // recursion
        int sum = values[u];
        for (auto v : graph[u]) {
            if (!visit[v]) {
                sum += dfs(values, k, graph, visit, v) % k;
            }
        }
        // Validate sum
        if (sum % k == 0) {
            cnt++;
            return 0;
        }
        return sum;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, 
                                vector<int>& values, int k) {
        cnt = 0;
        vector<int> graph[n];
        // Build graph
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visit(n, false);
        dfs(values, k, graph, visit, 0);
        return cnt;
    }
};

int main() {
  return 0;
}
