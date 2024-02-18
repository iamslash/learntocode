/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <functional>

// // 844ms 11.69%
// // O(SN) O(N)
// class Solution {
//  public:
//   std::vector<int> findSubstring(std::string s,
//                                  std::vector<std::string>& W) {
//     std::vector<int> rslt;
//     if (s.empty() || W.empty())
//       return rslt;
//     int n = W.size();
//     int k = W[0].size();
//     for (int i = 0; i + n * k <= s.size(); ++i) {
//       std::map<std::string, int> mp;
//       for (const auto& ss : W)
//         mp[ss] = mp.count(ss) ? mp[ss] + 1 : 1;
      
//       for (int j = 0; j < n; ++j) {
//         // if (i == 13) {
//         //   printf("j: %d, cnt: %d\n", j, mp.size());
//         // }
//         std::string ss = s.substr(i + j * k, k);
//         if (mp.count(ss) == 0)
//           break;
//         if (mp[ss] > 0)
//           mp[ss] -= 1;
//         if (mp[ss] == 0)
//           mp.erase(ss);
//       }
//       if (mp.empty())
//         rslt.push_back(i);
//     }
//     return rslt;
//   }
// };

// 112ms 69.32%
class Solution {
 public:
  std::vector<int> findSubstring(const std::string& s,
                                 const std::vector<std::string>& W) {
    std::vector<int> rslt;
    if (s.empty() || W.empty())
      return rslt;
    int n = W.size();
    int k = W[0].size();
    int sumhash = 0;
    std::hash<std::string> hashfn;
    for (const auto& ss : W)
      sumhash += hashfn(ss);

    for (int i = 0; i + n * k <= s.size(); ++i) {
      int sum = sumhash;
      for (int j = 0; j < n; ++j) {
        sum -= hashfn(s.substr(i + j * k, k));
      }
      if (sum == 0)
        rslt.push_back(i);
    }
    return rslt;
  }
};

int main() {
  // std::string s = "barfoothefoobarman";
  // std::vector<std::string> W = {
  //   "foo",
  //   "bar"
  // };

  // std::string s = "wordgoodgoodgoodbestword"  ;
  // std::vector<std::string> W = {"word","good","best","good"};


  std::string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
  std::vector<std::string> W = {"fooo","barr","wing","ding","wing"};

  Solution sln;
  auto rslt = sln.findSubstring(s, W);
  for (int a : rslt)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
