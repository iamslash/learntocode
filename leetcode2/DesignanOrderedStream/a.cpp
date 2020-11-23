/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// 140ms 100.00% 84.2MB 20.00%
// brute force
// insert: O(N) O(N)
class OrderedStream {
 private:
  vector<string> data;
  int pos = 0;
 public:
  OrderedStream(int n) {
    data.resize(n);
  }    
  vector<string> insert(int id, string val) {
    int idx = id - 1;
    data[idx] = val;
    vector<string> ans;
    while (pos < data.size() && data[pos].size() > 0) {
      ans.emplace_back(data[pos++]);
    }
    return ans;
  }
};
