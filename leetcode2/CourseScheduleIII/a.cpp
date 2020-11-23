/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//                                         i
//   C: 100,200 1000,1250 200,1300 2000,3200
//  pq: 100 200 1000 
// bnd: 1300

// 504ms 86.67% 56.6MB 51.16%
// greedy algorithm
// O(NlgN) O(N)
class Solution {
 public:
  int scheduleCourse(vector<vector<int>>& C) {
    sort(C.begin(), C.end(), [](const vector<int>& a,
                                const vector<int>& b) {
                               return a[1] < b[1];
                             });
    priority_queue<int> pq;
    int bnd = 0;
    for (auto& course : C) {
      pq.push(course[0]);
      bnd += course[0];
      if (bnd > course[1]) {
        bnd -= pq.top(); pq.pop();        
      }
    }
    return pq.size();
  }
};
