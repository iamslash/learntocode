/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

// Input:
// words = ["This", "is", "an", "example", "of", "text", "justification."]
// maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]

using namespace std;

// 0ms 100.00% 7.5MB 77.81%
// probe and forward
class Solution {
 public:
  vector<string> fullJustify(vector<string>& W, int maxWidth) {
    int n = W.size();
    vector<string> ans;
    //   k: index of W, 0 based on a line
    // len: length of a line
    for (int i = 0, k, len; i < n; i += k) {
      for (k = 0, len = 0; i + k < n &&
               len + W[i+k].size() <= maxWidth - k; ++k) {
        len += W[i+k].size();
      }
      string line = W[i];
      for (int j = 0; j < k-1; ++j) {
        if (i + k >= n) {
          line += " ";
        } else {
          line += string((maxWidth - len) / (k - 1) +
                         (j < (maxWidth - len) % (k - 1)), ' ');
        }
        line += W[i+j+1];
      }               
      line += string(maxWidth - line.size(), ' ');
      ans.push_back(line);
    }
    return ans;
  }
};
