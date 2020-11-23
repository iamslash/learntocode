/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>

// 012
// 345

// 
// 123405

// 8ms 39.58%
// BFS
// O(3^N) O(N)
class Solution {
 public:
  int slidingPuzzle(std::vector<std::vector<int>>& B) {
    int step = 0;
    std::unordered_set<std::string> ust;
    std::queue<std::pair<int, std::string>> Q;
    std::string s;
    for (int y = 0; y < B.size(); ++y)
      for (int x = 0; x < B[0].size(); ++x)
        s += '0' + B[y][x];
    Q.push({0, s});
    ust.insert(s);
    std::unordered_map<int, std::vector<int>> moves =
        {
          {0, {1, 3}},
          {1, {0, 2, 4}},
          {2, {1, 5}},
          {3, {0, 4}},
          {4, {1, 3, 5}},
          {5, {2, 4}},
        };

    while (!Q.empty()) {
      auto pr = Q.front(); Q.pop();
      std::string u = pr.second;
      int ulv = pr.first;
      
      // printf("%d %s\n", ulv, u.c_str());

      if (u == "123450") {
        return ulv;
      }

      int zpos = u.find('0');
      for (int npos : moves[zpos]) {
        std::string v = u;
        std::swap(v[zpos], v[npos]);
        if (ust.count(v) == 0) {
          Q.push({ulv+1, v});
          ust.insert(v);
          // printf("  %d %s\n", ulv+1, v.c_str());
        }
      }
    }

    return -1;    
  }
};

int main() {

  // std::vector<std::vector<int>> B = {
  //   {1, 2, 3},
  //   {4, 0, 5}
  // };
  std::vector<std::vector<int>> B = {
    {4, 1, 2},
    {5, 0, 3}
  };

  Solution sln;
  printf("%d\n", sln.slidingPuzzle(B));
  
  return 0;
}
