/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

// 32ms 100.00%
// 14.1MB 1.84%
// O(S^P) O(S)
class Solution {
 public:
  int shoppingOffers(
      std::vector<int>& P,
      std::vector<std::vector<int>>& S,
      std::vector<int>& N) {
    int rslt = std::inner_product(P.begin(), P.end(), N.begin(), 0);

    for (const auto& offer : S) {
      auto NN = useOffer(N, offer);
      if (NN.empty())
        continue;
      rslt = std::min(rslt, offer.back() + shoppingOffers(P, S, NN));
    }

    return rslt;
  }
  std::vector<int> useOffer(const std::vector<int>& need,
                          const std::vector<int>& offer) {
    int n = need.size();
    std::vector<int> rslt(n, 0);
    
    for (int i = 0; i < n; ++i) {
      if (offer[i] > need[i])
        return {};
      rslt[i] = need[i] - offer[i];
    }
    
    return rslt;
  }
};

int main() {
  std::vector<int> P = {2, 5};
  std::vector<std::vector<int>> S = {{3, 0, 5},{1, 2, 10}};
  std::vector<int> N = {3, 2};

  Solution sln;
  printf("%d\n", sln.shoppingOffers(P, S, N));
  
  return 0;
}
