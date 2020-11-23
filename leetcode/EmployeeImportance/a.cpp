/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <queue>

// Employee info
class Employee {
 public:
  int id;
  int importance;
  std::vector<int> subordinates;
};

// 28ms 91.14% 14.1MB 100.00%
// BFS, hashmap
// O(N) O(N)
class Solution {
 public:
  int getImportance(std::vector<Employee*> E, int id) {
    std::unordered_map<int, Employee*> ump;
    for (auto e : E) {
      ump[e->id] = e;
    }
    int sum = 0;
    std::queue<Employee*> bfsq;
    bfsq.push(ump[id]);
    while (bfsq.size()) {
      auto u = bfsq.front(); bfsq.pop();
      for (auto childId : u->subordinates) {
        bfsq.push(ump[childId]);
      }
      sum += u->importance;
    }
    return sum;
  }
};

int main() {
  return 0;
}
