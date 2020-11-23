/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>

using namespace std;
// [
//     ["David","3","Ceviche"],
//     ["Corina","10","Beef Burrito"],
//     ["David","3","Fried Chicken"],
//     ["Carla","5","Water"],
//     ["Carla","5","Ceviche"],
//     ["Rous","3","Ceviche"]
// ]

// [
//     ["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],
//     ["3","0","2","1","0"],
//     ["5","0","1","0","1"],
//     ["10","1","0","0","0"]
// ]

// 364ms 63.46% 92.2MB 25.68%
// hash table
// O(N) O(N)
class Solution {
 public:
  vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    vector<unordered_map<string, int>> tables(501);
    set<string> foods;
    for (auto &o : orders) {
      foods.insert(o[2]);
      ++tables[stoi(o[1])][o[2]];
    }
    vector<vector<string>> ans;
    for (int i = 0; i <= 500; ++i) {
      if (i > 0 && tables[i].empty())
        continue;
      ans.push_back(vector<string>());
      ans.back().push_back(i == 0 ? "Table" : to_string(i));
      for (auto it = foods.begin(); it != foods.end(); ++it) {
        ans.back().push_back(i == 0 ? *it : to_string(tables[i][*it]));
      }
    }
    return ans;
  }
};
