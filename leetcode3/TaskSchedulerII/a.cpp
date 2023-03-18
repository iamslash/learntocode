/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <cstdint>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

// space: 3
// tasks: 1 2 1 2 3 1
//                    i
//    ts: 9
//   map: 1 2 3
//        8 5 6
//        

// 311ms 25.00% 99.8MB 95.56%
// greedy, hash map
// O(N) O(N) 
class Solution {
public:
  long long taskSchedulerII(vector<int>& tasks, int space) {
    map<int, int64_t> taskTsMap;
    int64_t ts = 0;
    for (int task : tasks) {
      if (taskTsMap.count(task) > 0) {
        ts = max(ts, taskTsMap[task] + space + 1);
      }
      taskTsMap[task] = ts++;
    }
    return ts;
  }
};

// 247ms 86.94% 102MB 60.56%
// greedy, hash map
// O(N) O(N)
class Solution {
public:
  long long taskSchedulerII(vector<int>& tasks, int space) {
    unordered_map<int, int64_t> taskTsMap;
    int64_t ts = 0;
    for (int task : tasks) {
      if (taskTsMap.count(task) > 0) {
        ts = max(ts, taskTsMap[task] + space + 1);
      }
      taskTsMap[task] = ts++;
    }
    return ts;
  }
};


int main() {
  return 0;
}
