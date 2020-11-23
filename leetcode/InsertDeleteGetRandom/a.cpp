/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

// 56ms 91.96% 23.1MB 6.66%
// hash map
// O(N) O(1)
class RandomizedSet {
 private:
  unordered_map<int, int> valMap;
  vector<int> vals;
 public:
  bool insert(int val) {
    if (!valMap.emplace(val, vals.size()).second)
      return false;
    vals.emplace_back(val);
    return true;
  }
  bool remove(int val) {
    auto it = valMap.find(val);
    if (it == valMap.end())
      return false;
    int last = vals.back();
    valMap[last] = it->second;
    vals[it->second] = last;
    valMap.erase(it);
    vals.pop_back();
    return true;
  }
  int getRandom() {
    int idx = rand() % vals.size();
    return vals[idx];
  }
};

int main() {
  return 0;
}
