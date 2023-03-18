/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// 39ms 41.46% 28.4MB 11.58%
// brute force
// O(QD) O(Q)
class Solution {
private:
  int dist(string a, string b) {
    int n = a.size(), cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i] && ++cnt > 2) {
        break;
      }
    }
    return cnt;
  }
public:
  vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    vector<string> ans;
    for (string query : queries) {
      for (string word : dictionary) {
        if (dist(query, word) <= 2) {
          ans.push_back(query);
          break;
        }
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
