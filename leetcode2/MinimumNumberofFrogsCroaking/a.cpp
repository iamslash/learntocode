/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Reference: https://leetcode.com/problems/minimum-number-of-frogs-croaking/discuss/586653/C%2B%2B-Python-Java-Lucid-code-with-documened-comments-%2B-Visualization

// hash table
// O(S) O(1)
class Solution {
 private:
  unordered_map<char, int> freq;
  bool isValid() {
    return (freq['c'] >= freq['r']) &&
        (freq['r'] >= freq['o']) &&
        (freq['o'] >= freq['a']) &&
        (freq['a'] >= freq['k']);        
  }
 public:
  int minNumberOfFrogs(string s) {
    int cnt = 0;
    int ans = 0;
    for (char c : s) {
      freq[c]++;
      if (!isValid())
        return -1;
      if (c == 'c') {
        cnt++;
      } else if (c == 'k') {
        cnt--;
      }
      ans = max(ans, cnt);
    }
    return cnt == 0 ? ans : -1;
  }
};
