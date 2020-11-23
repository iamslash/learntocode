/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_multimap>

// BFS
class Solution {
 public:
  std::vector<int> killProcess(
      std::vector<int>& pid, std::vector<int>& ppid, int kill) {
    std::vector<int> rslt;
    std::unordered_multimap<int, int> proc;
    for (int i = 0; i < pid.size(); ++i)
      proc.emplace(ppid[i], pid[i]);
    std::queue<int> q;
    q.push(kill);
    while (q.size()) {
      int p = q.front(); q.pop();
      rslt.push_back(p);
      auto pr = proc.equal_range(p);
      for (auto it = pr.first; it != pr.second; ++it) {
        q.push(it->second);
        printf("%d %d\n", p, it->second);
      }
    }
    return rslt;
  }
};

int main() {

  // std::vector<int> pid = {1, 3, 10, 5};
  // std::vector<int> ppid = {3, 0, 5, 3};
  // int kill = 5;
  std::vector<int> pid = {1, 2, 3, 4, 5};
  std::vector<int> ppid = {0, 1, 1, 1, 1};
  int kill = 1;

  Solution sln;
  auto rslt = sln.killProcess(pid, ppid, kill);
  for (int a : rslt)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
