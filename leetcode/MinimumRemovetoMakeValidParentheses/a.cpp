/* Copyright (C) 2024 by iamslash */

#include <cstdio>
#include <string>
#include <stack>
#include <set>

using namespace std;

// 33ms 20.30% 13.2MB 31.56%
// stack
// O(N) O(N)
class Solution {
public:
  string minRemoveToMakeValid(string s) {
    stack<int> stck;
    set<int> rightSet;

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        stck.push(i);
      } else if (s[i] == ')') {
        if (!stck.empty()) {
          stck.pop();
        } else {
          rightSet.insert(i);
        }
      }
    }

    while (!stck.empty()) {
      rightSet.insert(stck.top());
      stck.pop();
    }

    string ans;
    for (int i = 0; i < s.size(); ++i) {
      if (rightSet.find(i) == rightSet.end()) {
        ans += s[i];
      }
    }

    return ans;    
  }
};

//        i
// s: ))((
//    ____
//     i
// l: 0

//       i
// s: ()()
//     
//     
// l: 0

// Idea: back and forward
//
// `leftCnt` is the count of left parentheses.
// Traverse forward and update unmatched right parentheses with '_'.
// Traverse backward and update unmatched left parentheses with '_'.
//
// Do not need stack because the order of parentheses 
// is not imortant.
//
// 21ms 67.25% 12.2MB 66.80%
// back and forth
// O(N) O(1)
class Solution {
public:
  string minRemoveToMakeValid(string s) {
    int leftCnt = 0, n = s.size();

    // Traverse forward
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        leftCnt++;
      } else if (s[i] == ')' && leftCnt == 0) {
        s[i] = '_';
      } else if (s[i] == ')' && leftCnt >= 1) {
        leftCnt--;
      }
    }

    // Traverse backward
    for (int i = n - 1; i >= 0 && leftCnt > 0;--i) {
      if (leftCnt >= 1 && s[i] == '(') {
        s[i] = '_';
        leftCnt--;
      }
    }

    string ans;
    for (int i = 0; i < n; ++i) {
      if (s[i] != '_') {
        ans.push_back(s[i]);
      }
    }
    
    return ans;    
  }
};

int main() {
  return 0;
}
