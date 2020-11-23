/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 76ms 57.14% 17.6MB 85.71%
// greedy, sort
// O(NlgN) O(1)
class Solution {
 private:
  void printV(vector<int>& A) {
    for (int a : A)
      printf("%d ", a);
    printf("\n");
  }
 public:
  int minDeletions(string s) {
    vector<int> freqs(26);
    for (char c : s) {
      freqs[c-'a']++;
    }
    sort(freqs.begin(), freqs.end(), greater<int>());
    // printV(freqs);
    int ans = 0;
    for (int i = 1; i < 26; ++i) {
      if (freqs[i] > 0 && freqs[i-1] <= freqs[i]) {
        int diff = freqs[i-1] == 0 ? freqs[i] : freqs[i] - freqs[i-1] + 1;
        ans += diff;
        freqs[i] -= diff;
      }
    }
    return ans;
  }
};

// 64ms 100.00% 17.7MB 85.71%
// greedy, hash set
// O(N) O(1)
class Solution {
 public:
  int minDeletions(string s) {
    vector<int> freqs(26);
    int ans = 0;
    unordered_set<int> used;
    for (char c : s)
      freqs[c-'a']++;
    for (int i = 0; i < 26; ++i) {
      int cnt = freqs[i];
      while (cnt > 0 && !used.insert(cnt).second) {
        --cnt;
        ++ans;
      }
    }
    return ans;
  }
};
