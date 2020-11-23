/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

// i
// ababcbacadefegdehijhklij
//  maxidx: -1
// lastidx:  0
//
// 4ms 99.47%
class Solution {
 public:
  std::vector<int> partitionLabels(std::string S) {
    std::vector<int> finalidxs(26, 0);  // finally appeared index of char
    for (int i = 0; i < S.size(); ++i)
      finalidxs[S[i]-'a'] = i;
    std::vector<int> rslt;
    //  maxidx: max last index
    // lastidx: last grouped index
    int maxidx = -1, lastidx = 0;
    for (int i = 0; i < S.size(); ++i) {
      maxidx = std::max(maxidx, finalidxs[S[i]-'a']);
      if (i == maxidx) {
        rslt.push_back(maxidx - lastidx + 1);
        lastidx = i + 1;
      }
    }
    return rslt;
  }
};

int main() {

  Solution sln;
  auto rslt = sln.partitionLabels("ababcbacadefegdehijhklij");
  // auto rslt = sln.partitionLabels("ababbbbbbbbbbb");
  for (int a : rslt)
    printf("%d ", a);
  printf("\n");
  return 0;
}
