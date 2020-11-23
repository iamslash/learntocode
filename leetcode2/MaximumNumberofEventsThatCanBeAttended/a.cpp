/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;


// [[1,2],[1,2],[3,3],[1,5],[1,5]]
//   2 3
//   2 3
// 1       5
// 1       5

// // TLE
// // greedy, sort
// // O(NlgN) O(N)
// class Solution {
//  public:
//   int maxEvents(vector<vector<int>>& E) {
//     sort(E.begin(), E.end(), [](const vector<int>& a,
//                                 const vector<int>& b) {
//                                if (a[1] == b[1])
//                                  return a[0] < b[0];
//                                return a[1] < b[1];
//                              });
//     int cnt = 0, i = 0;
//     unordered_set<int> seen;
//     for (auto& e : E) {
//       for (int i = e[0]; i <= e[1]; ++i) {
//         if (seen.insert(i).second) {
//           cnt++;
//           break;
//         }        
//       }
//     }
//     return cnt;
//   }
// };

// 1228ms 20.33% 84.7MB 100.00%
// priority queue
// O(NlgN) O(N)
class Solution {
 public:
  int maxEvents(vector<vector<int>>& E) {
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(E.begin(), E.end());
    int i = 0, j = 0, cnt = 0, n = E.size();
    while (pq.size() > 0 || i < n) {
      if (pq.size() == 0)
        j = E[i][0];
      while (i < n && E[i][0] <= j)
        pq.push(E[i++][1]);
      pq.pop();
      ++cnt, ++j;
      while (pq.size() > 0 && pq.top() < j)
        pq.pop();      
    }
    return cnt;
  }
};
