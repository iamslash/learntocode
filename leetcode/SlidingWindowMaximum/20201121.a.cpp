/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/837/

#include <cstdio>
#include <vector>
#include <limits>
#include <deque>

// .  
// 7 2 4
class Solution {
 public:
  std::vector<int> maxSlidingWindow(std::vector<int>& V, int k) {
    std::vector<int> rs; 
    std::deque<int> dq;  // sorted by descending
    for (int i = 0; i < V.size(); ++i) {

      // printf("%2d | ", i);
      // for (int j = 0; j < dq.size(); ++j)
      //   printf("%d ", V[dq[j]]);
      // printf("\n");     
      
      // check maximum candidates
      while (dq.size() > 0 && V[dq.back()] < V[i])
        dq.pop_back();
      dq.push_back(i);

      // printf("  %2d | ", i);
      // for (int j = 0; j < dq.size(); ++j)
      //   printf("%d ", V[dq[j]]);
      // printf("\n");     
      
      
      // get max value in slide
      if (dq.size() > 0 && i >= k - 1)
        rs.push_back(V[dq.front()]);

      // removes one not in slide
      if (dq.size() > 0 && dq.front() <= i - k + 1)
        dq.pop_front();
      // printf("%2d dq.front: %d\n", i, V[dq.front()]);      
    }
    return rs;
  }
};

int main() {
  // std::vector<int> V = {1, 3, -1, -3, 5, 3, 6, 7};
  // int k = 3;
  std::vector<int> V = {7, 2, 4};
  int k = 2;
  
  Solution sln;
  auto r = sln.maxSlidingWindow(V, k);
  for (int rr : r) {
    printf("%d ", rr);
  }
  printf("\n");
  
  return 0;
}
