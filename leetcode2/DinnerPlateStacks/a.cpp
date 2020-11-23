/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <map>
#include <set>
#include <vector>

using namespace std;

// 1224ms 56.33% 200.4MB 73.80%
// hash map
//       push: O(1) O(N)
//        pop: O(N) O(N)
// popAtStack: O(1) O(N)
class DinnerPlates {
 private:
  int cap;
  map<int, vector<int>> stckMap;
  set<int> freeSet;
 public:
  DinnerPlates(int capacity) {
    cap = capacity;
  }
    
  void push(int val) {
    if (freeSet.empty())
      freeSet.insert(stckMap.size());
    stckMap[*freeSet.begin()].push_back(val);
    if (stckMap[*freeSet.begin()].size() == cap)
      freeSet.erase(freeSet.begin());
  }
    
  int pop() {
    while (stckMap.size() && stckMap.rbegin()->second.empty()) {
      stckMap.erase(stckMap.rbegin()->first);
    }
    if (stckMap.empty())
      return -1;
    return popAtStack(stckMap.rbegin()->first);
  }
    
  int popAtStack(int idx) {
    if (stckMap[idx].empty())
      return -1;
    int val = stckMap[idx].back();
    stckMap[idx].pop_back();
    freeSet.insert(idx);
    if (stckMap[idx].empty())
      stckMap.erase(idx);
    return val;
  }
};
