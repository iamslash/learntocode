/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

//             i
//   students: 1 1 0 0
//                   j
// sandwiches: 0 1 0 1
//
//             i
//   students: 1 
//             j
// sandwiches:

//                         i
//   students: 1 1 1 0 0 1
//                   j
// sandwiches: 1 0 0 0 1 1
//

// 4ms 80.00% 8.9MB 100.00%
// brute force
// O(N) O(1)
class Solution {
 public:
  int countStudents(vector<int>& students,
                    vector<int>& sandwiches) {
    int cnts[] = {0, 0}, n = students.size(), i = 0;
    for (int student : students) {
      cnts[student]++;
    }
    for (i = 0; i < n && cnts[sandwiches[i]] > 0; ++i) {
      cnts[sandwiches[i]]--;
    }
    return n - i;
  }
};
