/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 0ms 100.00% 7MB 29.30%
// O(N) O(N)
class Solution {
 private:
  string getRange(int64_t s, int64_t e) {
    string r = to_string(s);
    if (e > s)
      r += "->" + to_string(e);
    return r;
  }
 public:
  vector<string> findMissingRanges(
      vector<int>& A, int64_t lo, int64_t hi) {
    vector<string> ans;
    int64_t miss = lo;
    A.push_back(hi + 1);
    for (int num : A) {
      if (miss < num) {
        ans.push_back(getRange(miss, num - 1));
      }
      miss = num + 1;
    }
    return ans;
  }
};

int main() {

  vector<int> V = {0, 1, 3, 50, 75};
  // vector<int> V = {};
  int lo = 0, hi = 99;
  Solution sln;
  auto r = sln.findMissingRanges(V, lo, hi);
  for (auto& s : r)
    printf("%s ", s.c_str());
  printf("\n");
  
  return 0;
}
