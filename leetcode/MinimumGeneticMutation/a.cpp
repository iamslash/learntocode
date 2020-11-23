/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>

// 0ms 100.00%
class Solution {
 private:
  bool is_adj(std::string a, std::string b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] != b[i]) {
        ++cnt;
        if (cnt > 1)
          return false;
      }
    }
    return cnt == 1;
  }
 public:
  int minMutation(std::string start, std::string end,
                  std::vector<std::string>& bank) {
    if (bank.empty())
      return -1;
    if (std::find(bank.begin(), bank.end(), end) == bank.end())
      return -1;

    if (std::find(bank.begin(), bank.end(), start) == bank.end())
      bank.push_back(start);
    int n = bank.size();
    std::vector<std::unordered_set<int>> adj(n, std::unordered_set<int>());
    std::vector<bool> visit(n, false);

    // set adj
    int ns = 0;
    for (int i = 0; i < n; ++i) {
      if (bank[i] == end)
        ns = i;
      for (int j = 0; j < n; ++j) {
        // printf("%s %s\n", bank[i].c_str(), bank[j].c_str());
        if (is_adj(bank[i], bank[j])) {
          adj[i].insert(j);
          // printf("%d-%d\n", i, j);
        }
      }
    }

    // BFS
    std::queue<std::pair<int, int>> q;
    q.push({0, ns});
    while (!q.empty()) {
      auto pr = q.front(); q.pop();
      int lv = pr.first;
      int u  = pr.second;
      visit[u] = true;

      if (bank[u] == start)
        return lv;

      for (int v : adj[u]) {
        if (!visit[v])
          q.push({lv+1, v});
      }
    }
    return -1;
  }
};

int main() {
  // std::string s = "AACCGGTT";
  // std::string e = "AACCGGTA";
  // std::vector<std::string> V = {"AACCGGTA"};
  // std::string s = "AACCGGTT";
  // std::string e = "AAACGGTA";
  // std::vector<std::string> V = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
  // std::string s = "AAAAACCC";
  // std::string e = "AACCCCCC";
  // std::vector<std::string> V = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
  // std::string s = "AACCGGTT";
  // std::string e = "AACCGGTA";
  // std::vector<std::string> V = {};
  // std::string s = "AACCGGTT";
  // std::string e = "AACCGGTA";
  // std::vector<std::string> V = {};
  // std::string s = "AAAAAAAA";
  // std::string e = "CCCCCCCC";
  // std::vector<std::string> V = {"AAAAAAAA","AAAAAAAC","AAAAAACC","AAAAACCC","AAAACCCC","AACACCCC","ACCACCCC","ACCCCCCC","CCCCCCCA"};
  std::string s = "AAAAAAAA";
  std::string e = "CCCCCCCC";
  std::vector<std::string> V = {"AAAAAAAA","AAAAAAAC","AAAAAACC","AAAAACCC","AAAACCCC","AACACCCC","ACCACCCC","ACCCCCCC","CCCCCCCA","CCCCCCCC"};

  Solution sln;
  printf("%d\n", sln.minMutation(s, e, V));
  
  return 0;
}
