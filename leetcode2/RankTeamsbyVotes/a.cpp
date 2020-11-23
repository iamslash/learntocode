/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// 28ms 62.12% 10.7MB 100.00%
// sort
// O(NM) O(1)
class Solution {
 public:
  string rankTeams(vector<string>& V) {
    vector<vector<int>> C(26, vector<int>(27));
    for (char c : V[0])
      C[c - 'A'][26] = c;
    for (auto& v : V) {
      for (int i = 0; i < v.size(); ++i) {
        --C[v[i] - 'A'][i];
      }
    }
    sort(C.begin(), C.end());
    string ans;
    printf("%d", V[0].size());
    for (int i = 0; i < V[0].size(); ++i) {
      ans += C[i][26];
    }
    return ans;
  }
};

int main() {
  return 0;
}
