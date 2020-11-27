/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

//                          i
//    T: 73 74 75 71 69 72 76 73
// stck:  2    
//  ans:  1  1  0  4  1  1

// Time limit
// monotone stack
// O(N) O(N)
class Solution {
 private:
  void printV(vector<int>& V) {
    for (int a : V)
      printf("%d ", a);
    printf("\n");
  }
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    stack<int> stck;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      while (stck.size() && T[stck.top()] < T[i]) {
        int j = stck.top(); stck.pop();
        ans[j] = i - j;
        printV(ans);
      }
      stck.push(i);
    }
    while (stck.size()) {
      int j = stck.top(); stck.pop();
      ans[j] = 0;
    }
    return ans;
  }
};

// 144ms 14.44% 42.1MB 19.49%
// monotone stack
// O(N) O(N)
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    if (T.empty())
      return {};
    int n = T.size();
    vector<int> ans(n);
    stack<int> stck;
    stck.push(0);
    for (int i = 1; i < n; ++i) {
      while (stck.size() && T[stck.top()] < T[i]) {
        int j = stck.top(); stck.pop();
        ans[j] = i - j;
      }
      stck.push(i);
    }
    return ans;
  }
};



//        i  j
//    T: 73 74 75 71 69 72 76 73
//                               
//  ans:  1  1  4  2  1  1

// 112 ms 81.28% 40.4MB 65.26%
// two pointers
// O(N) O(1)
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    int n = t.size();
    vector<int> ans(n);
    for (int i = n-1; i >= 0; --i) {
      int j = i + 1;
      while (j < n && T[i] >= T[j]) {
        if (ans[j] > 0) {
          j += ans[j];
        } else {
          j = n;
        }
      }
      if (j < n) {
        ans[i] = j - i;
      }
    }
    return ans;
  }
};
