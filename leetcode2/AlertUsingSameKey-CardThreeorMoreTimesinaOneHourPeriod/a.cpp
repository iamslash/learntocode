/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 412ms 91.35% 100.4MB 5.17%
// hash map
// O(NlgN) o(N)
class Solution {
 private:
  int getNum(string& s) {
    return stoi(s.substr(0,2)) * 60 + stoi(s.substr(3,2));
  }
 public:
  vector<string> alertNames(vector<string>& keyName,
                            vector<string>& keyTime) {
    unordered_map<string, vector<int>> name2times;
    for (int i = 0; i < keyName.size(); ++i) {
      name2times[keyName[i]].push_back(getNum(keyTime[i]));
    }
    vector<string> ans;
    for (auto& pr : name2times) {
      auto& times = pr.second;
      sort(times.begin(), times.end());
      for (int i = 0, j = 0; i < times.size(); ++i) {
        while (j < times.size() && times[j] - times[i] <= 60) {
          j++;
        }
        if (j - i > 2) {
          ans.push_back(pr.first);
          break;
        }          
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};
