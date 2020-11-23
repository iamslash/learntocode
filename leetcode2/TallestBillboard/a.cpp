/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <algorithm>

using namespace std;

// // iterative dynamic programming
// // 476ms 22.99% 60MB 37.36%
// // O(RD) O(RD)
// class Solution {
//  public:
//   int tallestBillboard(vector<int>& rods) {
//     unordered_map<int, int> C;
//     C[0] = 0;
//     for (int x : rods) {
//       unordered_map<int, int> curMap(C);
//       for (auto& pr : curMap) {
//         int d = pr.first;
//         C[d+x] = max(C[d+x], curMap[d]);
//         C[abs(d-x)] = max(C[abs(d-x)], curMap[d] + min(d, x));
//       }
//     }
//     return C[0];
//   }
// };

// // 52ms 89.08% 16.7MB 63.79%
// // recursive dynamic programming
// class Solution {
//  private:
//   int dfs(vector<vector<int>>& C, vector<int>& rods,
//            int tgt, int i, int sum1, int sum2) {
//     if (sum1 > tgt || sum2 > tgt)
//       return -1;
//     if (i >= rods.size())
//       return sum1 == sum2 ? sum1 : -1;
//     int& r = C[i][abs(sum1-sum2)];
//     if (r == -2) {
//       r = max(-1, max({dfs(C, rods, tgt, i + 1, sum1, sum2),
//                        dfs(C, rods, tgt, i + 1, sum1 + rods[i], sum2),
//                        dfs(C, rods, tgt, i + 1, sum1, sum2 + rods[i])}) - max(sum1, sum2));
//     }
//     return r + (r == -1 ? 0 : max(sum1, sum2));    
//   }
//  public:
//   int tallestBillboard(vector<int>& rods) {
//     int half = accumulate(rods.begin(), rods.end(), 0) / 2;
//     vector<vector<int>> C(rods.size(), vector<int>(half + 1, -2));
//     return max(0, dfs(C, rods, half, 0, 0, 0));
//   }
// };

//             k
// rods: 6 3 2 1
//  sum: 12
//                                  i
//    C: 0 1 2 3 4 5 6 7 8 9 10 11 12
//       2 1 1 2 1 1 2 1 1 2  1  1  1
//       

// 20ms 100.00% 8.8MB 72.99%
// iterative dynamic programming
class Solution {
 public:
  int tallestBillboard(vector<int>& rods) {
    int n = rods.size();    
    int sum = accumulate(rods.begin(), rods.end(), 0);
    sort(rods.begin(), rods.end(), [](int a, int b){return a > b;});
    vector<int> C(sum+1, 0);
    C[0] = 2; 
    for(int k = 0;k < n; k++){
      for(int i = sum; i >= rods[k]; i--){
        if(C[i - rods[k]])
          C[i]++;
      }
    }
    for(int i = sum - (sum % 2); i >= 0; i -= 2){
      if(C[i] && C[i/2] > 1)
        return i/2;
    }
    return 0;
  }
};
