/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>
#include <queue>
#include <map>

using namespace std;

// Wrong answer
// [1998]
// 1999
// 2000
// 2000
// BFS
// O(N) O(N)
class Solution {
 public:
  int minimumJumps(vector<int>& forbidden,
                   int a, int b, int x) {
    unordered_set<int> forbiddenSet(forbidden.begin(),
                                    forbidden.end());
    // visit[0]: visit for reaching from left
    // visit[1]: visit for reaching from right
    vector<vector<int>> visit(2, vector<int>(5000));
    // {pos, last jump was backward ?}
    queue<pair<int, bool>> q;
    q.push({0, false});
    visit[0][0] = 1;
    visit[1][0] = 1;
    int step = 0;
    while (q.size()) {
      int n = q.size();
      while (n > 0) {
        n--;
        int pos = q.front().first;
        bool flag = q.front().second;
        q.pop();
        if (pos == x)
          return step;
        int forward = pos + a;
        int backward = pos - b;
        if (forward < 5000 && visit[0][forward] == 0
            && !forbiddenSet.count(forward)) {
          q.push({forward, false});
          visit[0][forward] = 1;
        }
        if (backward >= 0 && visit[1][backward] == 0
            && !forbiddenSet.count(backward) &&
            !flag) {
          q.push({backward, true});
          visit[1][backward] = 1;
        }
      }
      step++;
    }
    return -1;
  }
};
