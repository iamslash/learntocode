/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 560ms 76.09% 54.3MB 67.31%
// brute force
// O(N^2) O(N^2)
class Solution {
 public:
  vector<int> peopleIndexes(vector<vector<string>>& F) {
    // build id
    int id = 0;
    unordered_map<string, int> ids;
    vector<vector<int>> favors(F.size());
    for (int i = 0; i < F.size(); ++i) {
      for (auto& company : F[i]) {
        if (!ids.count(company))
          ids[company] = id++;
        favors[i].push_back(ids[company]);
      }
    }
    for (auto& companies : favors) {
      sort(companies.begin(), companies.end());
    }
    vector<int> ans;
    for (int i = 0; i < favors.size(); ++i) {
      bool noSubset = true;
      for (int j = 0; j < favors.size() && noSubset; ++j) {
        if (i != j) {
          noSubset = !includes(favors[j].begin(), favors[j].end(),
                               favors[i].begin(), favors[i].end());
        }
      }
      if (noSubset) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
