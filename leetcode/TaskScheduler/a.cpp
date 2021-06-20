/* Copyright (C) 2021 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

// tasks: A A A B B B
//     n:2
//
// A B X A B X A B
//
// maxFreq: 3
// unitCnt: 2
// unitLen: 3
// slotCnt: 6
//     ans: 6+2

// 60ms 73.16% 34.4MB 88.47%
// math
// O(N) O(1)
class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> freqMap;
    int maxFreq = 0;
    for (char task : tasks) {
      freqMap[task]++;
      maxFreq = max(maxFreq, freqMap[task]);
    }
    int ans = (maxFreq-1) * (n+1);
    for (auto& pr : freqMap) {
      if (pr.second == maxFreq) {
        ans++;
      }
    }
    return max((int)tasks.size(), ans);
  }
};

int main() {
  return 0;
}
