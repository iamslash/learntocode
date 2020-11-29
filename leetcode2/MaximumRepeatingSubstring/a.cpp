/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// 0ms 100.00% 6.6MB 100.00%
// brute force
// O(N^2) O(N)
class Solution {
 public:
  int maxRepeating(string seq, string word) {
    int fnd = seq.find(word), ans = 0;
    string tmp = word;
    while (seq.find(tmp) != string::npos) {
      ans++;
      tmp += word;
    }
    return ans;
  }
};

// 4ms 25.00% 6.4MB 100.00%
// brute force, modulo
// O(N^2) O(1)
class Solution {
 public:
  int maxRepeating(string seq, string word) {
    int ans = 0, m = seq.size(), n = word.size();
    for (int q = 0; q < m; ++q) {
      int cnt = 0;
      for (int j = q; j < m; ++j) {
        if (seq[j] != word[cnt % n])
          break;
        cnt++;
      }
      ans = max(ans, cnt / n);
    }
    return ans;
  }  
};
