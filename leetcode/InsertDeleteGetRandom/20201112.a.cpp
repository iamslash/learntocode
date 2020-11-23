// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/112/design/813/

#include <cstdio>
#include <cassert>
#include <vector>
#include <unordered_map>


class RandomizedSet {
 private:
  std::unordered_map<int, int> m; // num: idx of v
  std::vector<int> v; // num
 public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if (m.emplace(val, v.size()).second == false)
      return false;
    v.push_back(val);
    return true;
  }
    
  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    auto it = m.find(val);
    if (it == m.end())
      return false;
    // there it is
    int last = v.back();
    m[last] = it->second;
    v[it->second] = last;
    m.erase(it);
    v.pop_back();

    return true;
  }
    
  /** Get a random element from the set. */
  int getRandom() {
    int idx = rand() % v.size();
    return v[idx];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main() {
  RandomizedSet s;
  assert(s.insert(1) == true);
  assert(s.insert(2) == true);
  assert(s.insert(3) == true);
  assert(s.remove(1) == true);
  assert(s.remove(4) == false);
  printf("%d\n", s.getRandom());
  printf("%d\n", s.getRandom());
  printf("%d\n", s.getRandom());
  
  return 0;
}
