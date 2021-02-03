/* Copyright (C) 2021 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

// 1352ms 6.77% 188.6MB 10.77%
// greedy, hash set
class Solution {
 private:
  int connected(unordered_set<int> uLangSet,
                unordered_set<int> vLangSet) {
    for (int lang : uLangSet) {
      if (vLangSet.count(lang)) {
        return true;
      }
    }
    return false;
  }
 public:
  int minimumTeachings(int n,
                       vector<vector<int>>& languages,
                       vector<vector<int>>& friendships) {
    vector<unordered_set<int>> langSets;
    for (auto& v : languages) {
      langSets.emplace_back(v.begin(), v.end());      
    }
    vector<pair<int, int>> notCons;
    for (auto& e : friendships) {
      int u = e[0], v = e[1];
      if (!connected(langSets[u-1], langSets[v-1])) {
        notCons.emplace_back(u-1, v-1);
      }
    }
    int minTeach = languages.size();
    for (int lang = 1; lang <= n; lang++) {
      unordered_set<int> usersToTeach;
      for (auto& e : notCons) {
        int u = e.first, v = e.second;
        if (!langSets[u].count(lang)) {
          usersToTeach.insert(u);
        }
        if (!langSets[v].count(lang)) {
          usersToTeach.insert(v);
        }
        minTeach = min<int>(minTeach, usersToTeach.size());
      }
    }
    return minTeach;
  }
};
