/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;



// 1 10 10
// 1 4 5
// 2 3 6

// Wrong Answer
// // back tracking
// // O(k) O(k)
// class Solution {
//  private:
//   int best = -1;
//   int k;
//   void dfs(vector<vector<int>>& M, int y, int sum) {
//     int h = M.size(), w = M[0].size();
//     // base
//     if (y == h) {
//       if (--k == 0) {
//         best = sum;
//       }
//       return;
//     }
   
//     // recursion
//     for (int x = 0; x < w; ++x) {
//       if (best >= 0)
//         return;
//       dfs(M, y+1, sum + M[y][x]);
//     }
//   }
//  public :
//   int kthSmallest(vector<vector<int>>& M, int K) {
//     k = K;
//     dfs(M, 0, 0);
//     return best;
//   }
// };

//       k: 5
//       M: 1 3 11
//          2 4 6
// cumsum : 0
// nxtsum : 1 3 11

// // 476ms 39.39% 33.4MB 60.87%
// // cumulative sum
// // O(k) O(k)
// class Solution {
//  public:
//   int kthSmallest(vector<vector<int>>& M, int k) {
//     vector<int> cumsum{0};
//     for (auto& row : M) {
//       vector<int> nxtsum;
//       for (int x : row) {
//         for (int sum : cumsum) {
//           nxtsum.push_back(sum+x);
//         }
//       }
//       sort(nxtsum.begin(), nxtsum.end());
//       nxtsum.resize(min(k, (int)nxtsum.size()));
//       swap(nxtsum, cumsum);
//     }
//     return cumsum.back();
//   }
// };

// 36ms 92.29% 8.7MB 92.63%
// binary search
class Solution {
 private:
  int count(vector<vector<int>>& M,
            int tgt, int y, int sum, int k) {
    int h = M.size(), w = M[0].size();
    if (sum > tgt)
      return 0;
    if (y == h)
      return 1;
    int ans = 0;
    for (int x = 0; x < w; ++x) {
      int cnt = count(M, tgt, y+1, sum+M[y][x], k-ans);
      if (cnt == 0)
        break;
      ans += cnt;
      if (ans > k)
        break;
    }
    return ans;
  }
 public:
  int kthSmallest(vector<vector<int>>& M, int k) {
    int h = M.size(), w = M[0].size();
    int left = h, right = w * 5000, ans = -1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      int cnt = count(M, mid, 0, 0, k);
      if (cnt >= k) {
        ans = mid;
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }
};
