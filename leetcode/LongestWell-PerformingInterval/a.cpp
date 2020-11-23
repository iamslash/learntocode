/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

//                    i
//     H: 9 9 6 0 6 6 9
//   cnt: 1 2 1 0-1-2-1 
//   ans: 1 2 3 
//  seen: 0-1-2
//        3 4 5
//        
//        

// 32ms 77.69% 11.8MB 100.00%
// O(N) O(N)
class Solution {
 public:
  int longestWPI(std::vector<int>& H) {
    int ans = 0, cnt = 0, n = H.size();
    std::unordered_map<int, int> seen;
    for (int i = 0; i < n; ++i) {
      cnt += H[i] > 8 ? 1 : -1;
      if (cnt > 0) {
        ans = i + 1;
      } else {
        if (!seen.count(cnt))
          seen[cnt] = i;
        if (seen.count(cnt - 1))
          ans = std::max(ans, i - seen[cnt - 1]);
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
