/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

// B: a b c a
//      i
// A: a a b c
//        j
//
//        i
// u: a b a c
//          j

// 152ms 66.04% 20.5MB 70.33%
// BFS
// O(N^2) O(N)
class Solution {
 public:
  int kSimilarity(string a, string b) {
    if (a == b)
      return 0;
    unordered_set<string> visit;
    queue<pair<string, int>> q;
    int step, beg = 0;
    while (beg < a.size()) {
      if (a[beg] != b[beg])
        break;
      beg++;
    }
    q.push({a, beg});
    visit.insert(a);
    while (q.size()) {
      int n = q.size();
      for (int k = 0; k < n; ++k) {
        auto item = q.front(); q.pop();
        string u = move(item.first);
        int i = item.second;
        // printf("%d {%s, %d}\n", q.size(), u.c_str(), i);
        if (u == b)
          return step;
        while (u[i] == b[i])
          ++i;
        for (int j = i+1; j < a.size(); ++j) {
          if (u[j] != b[i] || u[j] == b[j])
            continue;
          swap(u[i], u[j]);
          if (visit.count(u) == 0) {
            q.push({u, i+1});
            visit.insert(u);
          }
          swap(u[i], u[j]);
        }
      }
      ++step;
    }
    return step;
  }
};
