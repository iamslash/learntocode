/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// s: a b c
//    i
// t: a c d b c
//        j

//   s: a b c
//            i
//   t: a b c b c
//                j
// ans: 1

// 0ms 100.00% 6.6MB 83.53%
// two pointers
// O(ST) O(1)
class Solution {
 public:
  int shortestWay(string s, string t) {
    int i = 0, j = 0, ans = 0;
    while (j < t.size() && ans <= j) {
      if (i < s.size()) {
        if (s[i] == t[j]) {
          i++;
          j++;
        } else {
          i++;
        }
      } else {
        i = 0;
        ans++;
      }
      // printf("i: %d, j: %d, ans: %d\n", i, j, ans);
    }
    if (++ans > j)
      return -1;
    return ans;
  }
};


