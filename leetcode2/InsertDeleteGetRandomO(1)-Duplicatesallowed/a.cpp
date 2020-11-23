/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// nums: [{1,0}, {2,0}, {3,0}, {3,1}, {4,0}, {4,1}]
// vals: {{1 : [0]},
//        {2 : [1]},
//        {3 : [2, 3]},
//        {4 : [4,5]}}

// // 72ms 28.76% 21MB 100.00%
// // hash map
// // insert: O(1) O(N)
// // getRandom: O(1) O(N)
// // remove: O(1) O(N)
// class RandomizedCollection {
//  private:
//   std::vector<std::pair<int,int>> nums;
//   std::unordered_map<int, std::vector<int>> vals;
//  public:
//   RandomizedCollection() {
//   } 
//   bool insert(int val) {
//     bool b = vals.count(val) == 0;
//     vals[val].push_back(nums.size());
//     nums.push_back({val, vals[val].size()-1});
//     return b;
//   }
//   bool remove(int val) {
//     if (vals.count(val) == 0)
//       return false;
//     auto last = nums.back();
//     vals[last.first][last.second] = vals[val].back();
//     nums[vals[val].back()] = last;
//     vals[val].pop_back();
//     if (vals[val].empty())
//       vals.erase(val);
//     nums.pop_back();
//     return true;
//   }
//   int getRandom() {
//     return nums[rand() % nums.size()].first;
//   }
// };

// 80ms 25.29% 22.2MB 100.00%
// hash map
// insert: O(1) O(N)
// getRandom: O(1) O(N)
// remove: O(1) O(N)
class RandomizedCollection {
 private:
  std::vector<int> nums;
  std::unordered_map<int, std::unordered_set<int>> vals;
 public:
  bool insert(int val) {
    nums.push_back(val);
    vals[val].insert(nums.size()-1);
    return vals[val].size() == 1;
  }
  bool remove(int val) {
    if (vals.count(val) == 0)
      return false;
    auto it = vals.find(val);
    int i = *it->second.begin();
    it->second.erase(it->second.begin());
    nums[i] = nums.back();
    vals[nums.back()].insert(i);
    vals[nums.back()].erase(nums.size()-1);
    nums.pop_back();
    if (it->second.size() == 0)
      vals.erase(it);
    return true;
  }
  int getRandom() {
    return nums[rand() % nums.size()];
  }
};

int main() {
  return 0;
}
