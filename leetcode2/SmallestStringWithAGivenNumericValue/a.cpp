/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

//   n: 3
//   k: 27
// ans: z

// a b c d e
// f g h i j
// k l m n o
// p q r s t
// u v w x y
// z

//   n: 5
//   k: 72 71 
// ans: a  a

// 26*3=78
// 26*2=52

// 68ms 37.50% 21.3MB 50.00%
// O(N) O(N)
class Solution {
 public:
  string getSmallestString(int n, int k) {
    string ans(n, 'a');
    k -= n;
    int i = ans.size() - 1;
    while (k > 0) {
      int j = min(k, 25);
      ans[i] += j;
      k -= j;
      --i;
    }
    return ans;
  }
};

// 68ms 37.50% 21.5MB 50.00%
// O(N) O(N)
class Solution {
 public:
  string getSmallestString(int n, int k) {
    ans(n, 'a');
    k -= n;
    for (int i = n-1; i >= 0; --i) {
      int j = min(k, 25);
      ans[i] += j;
      k -= j;
    }
    return ans;
  }
};
