/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/114/others/826/

#include <cstdio>
#include <vector>
#include <algorithm>

// tasks = ["A","A","A","B","B","B"], n = 2
//
// A X X A X X A
// A B X A B X A B
//
//       max_freq: 3
// max_freq_tasks: 2
//       unit_len: 1
//       unit_cnt: 2
//          slots: 2
//     free_tasks: 0
//          idles: 2
//              r: 8
//
// max_freq
// max_freq_tasks
// unit_len    = n - (max_freq_tasks - 1)
// unit_cnt    = max_freq - 1
// slots       = unit_len * unit_cnt
// free_tasks  = tasks - max_freq * max_freq_tasks
// idles       = max(0, slots - free_tasks)
// r           = tasks + idles
class Solution {
public:
  int leastInterval(std::vector<char>& tasks, int n) {
    int freq[26] = {0,};
    int max_freq = 0;
    int max_freq_tasks = 0;
    for (char t : tasks) {
      int idx = t - 'A';
      freq[idx]++;
      if (max_freq == freq[idx]) {
        max_freq_tasks++;
      } else if (max_freq < freq[idx]) {
        max_freq = freq[idx];
        max_freq_tasks = 1;
      }
    }
    //
    int unit_len = n - (max_freq_tasks - 1);
    int unit_cnt = max_freq - 1;
    int slots = unit_len * unit_cnt;
    int free_tasks = tasks.size() - max_freq * max_freq_tasks;
    int idles = std::max(0, slots - free_tasks);
    
    return tasks.size() + idles;
  }
};

int main() {
  std::vector<char> v = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n = 2;
  
  Solution s;
  printf("%d\n", s.leastInterval(v, n));
  
  return 0;
}
