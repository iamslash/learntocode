/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <functional>
#include <vector>
#include <unordered_set>

//     S = S0 + S1 (S0 > S1)
//     d = S0 - S1
// S - d = S1 + S1
//     d = S - 2 * S1 (minimize d -> maximize S1

// C[i][j] = true  (there is    S1 whose sum is i and ends with S[j])
//         = false (there is no S1 whose sum is i and ends with S[j])

// class Solution {
//  public:
//   int lastStoneWeightII(std::vector<int>& stones) {
//     int SS = 0, S1 = 0, n = stones.size();
//     SS = std::accumulate(stones.begin(), stones.end(), 0, std::plus<int>());
//     std::vector<std::vector<bool>> C(SS+1, std::vector<bool>(n+1));
//     // magic seeds
//     for (int i = 0; i <= n; ++i)
//       C[0][i] = true;
//     for (int S = 1; S <= SS/2; ++S) {
//       for (int i = 1; i <= n; ++i) {
//         if (C[S][i-1] || (S >= stones[i-1] && C[S - stones[i-1]][i-1])) {
//           C[S][i] = true;
//           S1 = std::max(S1, S);
//         }
//       }
//     }
//     return SS - 2 * S1;
//   }
// };

// 20ms 30.05% 14.2MB 100.00%
// set
class Solution {
 public:
  int lastStoneWeightII(std::vector<int> &S) {
    std::unordered_set<int> ust = {0};
    for (int i : S) {
      std::unordered_set<int> tmp;
      for (int j : ust)
        tmp.insert({j - i, j + i});
      std::swap(ust, tmp);
    }
    int ans = INT_MAX;
    for (int w : ust)
      ans = std::min(ans, std::abs(w));
    return ans;
  }
};

int main() {
  return 0;
}
