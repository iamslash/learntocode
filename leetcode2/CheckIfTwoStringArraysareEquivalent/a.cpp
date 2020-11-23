/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// 4ms 66.67% 11.7MB 100.00%
// brute force
// O(N) O(N)
class Solution {
 public:
  bool arrayStringsAreEqual(vector<string>& word1,
                            vector<string>& word2) {
    string a, b;
    for (string& s : word1)
      a += s;
    for (string& s : word2)
      b += s;
    return a == b;
  }
};

// 8ms 33.33% 12.7MB 33.33%
// brute force
// O(N) O(N)
class Solution {
 public:
  bool arrayStringsAreEqual(vector<string>& word1,
                            vector<string>& word2) {
    string a = accumulate(word1.begin(), word1.end(), string());
    string b = accumulate(word2.begin(), word2.end(), string());
    return a == b;
  }  
};
