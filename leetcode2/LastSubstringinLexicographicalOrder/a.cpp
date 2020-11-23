/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <set>
#include <string_view>
#include <iostream>
#include <algorithm>

using namespace std;

// // Time Limit Exceeded
// // brute force
// // O(N^2S) O(N)
// class Solution {
//  public:
//   string lastSubstring(string s) {
//     int n = s.size();
//     set<string> wordSet;
//     for (int i = 0; i < n; ++i) {
//       for (int j = i; j < n; ++j) {
//         wordSet.insert(s.substr(i,j-i+1));
//       }
//     }
//     return *wordSet.rbegin();
//   }
// };


// // Time Limit Exceeded
// // brute force
// // O(NS) O(N)
// class Solution {
//  public:
//   string lastSubstring(string s) {
//     string ans;
//     int n = s.size();
//     for (int i = 0; i < n; ++i) {
//       if (s.substr(i) > ans)
//         ans = s.substr(i);
//     }
//     return ans;
//   }
// };

//     i
// a b a b

// // 1172ms 5.73% 13.4MB 93.76%
// class Solution {
//  public:
//   string lastSubstring(string_view s) {
//     string_view ans;
//     int n = s.size();
//     for (int i = 0; i < n; ++i) {
//       if (s.substr(i) > ans)
//         ans = s.substr(i);
//     }
//     return string(ans);
//   }
// };

// // 1144ms 6.91% 13.4MB 92.41%
// // string_view
// class Solution {
//  public:
//   Solution(){
//     ios_base::sync_with_stdio(false); 
//     cin.tie(NULL);    
//   }  
//   string lastSubstring(string_view s) {
//     string_view ans;
//     int n = s.size();
//     for (int i = 0; i < n; ++i) {
//       if (s.substr(i) > ans)
//         ans = s.substr(i);
//     }
//     return string(ans);
//   }
// };

// // 412ms 9.28% 13.7MB 90.05%
// // string_view
// class Solution {
//  public:
//   Solution(){
//     ios_base::sync_with_stdio(false); 
//     cin.tie(NULL);    
//   }  
//   string lastSubstring(string_view s) {
//     string_view ans;
//     int n = s.size();
//     if (all_of(s.begin(), s.end(), [&s](const char a) {
//                                      return a == s[0];
//                                    }))
//       return string(s);
//     for (int i = 0; i < n; ++i) {
//       if (s.substr(i) > ans)
//         ans = s.substr(i);
//     }
//     return string(ans);
//   }
// };

// 68ms 99.33% 13.4MB 93.76%
// brute force, no substr
class Solution {
 public:
  Solution(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
  }  
  string lastSubstring(string_view s) {
    string_view ans;
    int n = s.size();
    if (all_of(s.begin(), s.end(), [&s](const char a) {
                                     return a == s[0];
                                   }))
      return string(s);
    int max = INT_MIN;
    for (int i = 0; i < n; ++i) {
      if (max <= s[i]) {
        max = s[i];
        if (lexicographical_compare(ans.begin(), ans.end(),
                                    s.begin()+i, s.end()))
          ans = s.substr(i, n);
      }
    }
    return string(ans);
  }
};
