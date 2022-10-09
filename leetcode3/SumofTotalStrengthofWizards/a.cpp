/* Copyright (C) 2022 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

//           i
// strength: 1 3 1 2
//    lefts: - 0 - 2 
//   rights: 2 2 4 4
//
// 1 is min: 1 * 4
//           1
//           1 3
//           1 3 1
//           1 3 1 2
// 3 is min: 1 * 1
//             3
// 1 is min: 2 * 2
//               1
//               1 2
//             3 1
//             3 1 2
// 2 is min: 1 * 1
//                 2
//
//       ps:
//           1 3 5 7
//      pps:
//           1 4 9 16

// 520ms 39.92% 105.4MB 44.13%
// prefix sum, monotonic stack
// O(N) O(N)
class Solution {
public:
  int totalStrength(vector<int>& strength) {
    int64_t MOD = 1000000007;
    const int n = strength.size();
    // Build ps
    vector<int64_t> ps(n + 1, 0L);
    for (int i = 0; i < n; ++i) {
      ps[i + 1] = (ps[i] + strength[i]) % MOD;      
    }
    // Build pps
    vector<int64_t> pps(n + 2, 0L);
    for (int i = 0; i <= n; ++i) {
      pps[i + 1] = (pps[i] + ps[i]) % MOD;
    }
    // Build first idx on the left < cur strength
    vector<int> lefts(n, -1);
    vector<int> stck;
    for (int i = 0; i < n; ++i) {
      while (!stck.empty() && strength[stck.back()] >= strength[i]) {
        stck.pop_back();
      }
      lefts[i] = stck.empty() ? -1 : stck.back();
      stck.push_back(i);
    }
    // Build first idx on the right <= cur stength
    vector<int> rights(n, n);
    stck.clear();
    for (int i = n - 1; i >= 0; --i) {
      while (!stck.empty() && strength[stck.back()] > strength[i]) {
        stck.pop_back();
      }
      rights[i] = stck.empty() ? n : stck.back();
      stck.push_back(i);
    }
    // Sum it
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += (
              (pps[rights[i] + 1] - pps[i + 1]) * (i - lefts[i]) % MOD + MOD * 2 -
              (pps[i + 1] - pps[lefts[i] + 1]) * (rights[i] - i) % MOD) %
        MOD *
        strength[i] % MOD;
      ans %= MOD;
    }
    return (int)ans;
  }
};

//           i
// strength: 1 3 1 2
//    lefts: - 0 - 2 
//   rights: 2 2 4 4
//

int main() {
  return 0;
}
