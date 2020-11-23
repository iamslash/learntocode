/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>

// 12ms 50.16% 9.9MB 100.00% 
// two pointers
// O(N) O(N)
class Solution {

 private:
  int f(int x, int a, int b, int c) {
    return a * x * x + b * x + c;
  }
 public:
  std::vector<int> sortTransformedArray(
      std::vector<int>& V, int a, int b, int c) {
    if (V.empty())
      return {};
    int n = V.size();
    std::vector<int> rslt(n);
    int i = 0, j = n - 1;
    int s = 0, e = n - 1;
    while (s <= e) {
      int vs = f(V[s], a, b, c);
      int ve = f(V[e], a, b, c);
      if (a > 0) {
        if (vs >= ve) {
          rslt[j--] = vs;
          ++s;
        } else {
          rslt[j--] = ve;
          --e;
        }
      } else {
        if (vs <= ve) {
          rslt[i++] = vs;
          ++s;
        } else {
          rslt[i++] = ve;
          --e;
        }
      }
    }
    return rslt;
  }
};

int main() {

  std::vector<int> V = {-4, -2, 2, 4};
  int a = -1, b = 3, c = 5;

  // std::vector<int> V = {-98,-97,-93,-90,-89,-89,-86,-84,-82,-81,-78,-78,-73,-70,-68,-68,-67,-66,-63,-62,-61,-60,-59,-54,-54,-53,-50,-50,-48,-48,-47,-43,-43,-42,-42,-37,-33,-30,-28,-23,-21,-21,-20,-19,-19,-17,-17,-9,-7,-4,-3,-3,-2,0,0,7,8,11,11,20,21,25,27,30,33,33,36,40,40,41,49,50,50,52,54,61,64,65,65,67,69,72,73,74,74,76,78,79,81,83,84,84,85,85,86,88,89,89,93,97};
  // int a = 4, b = -64, c = 25;

  Solution sln;
  auto r = sln.sortTransformedArray(V, a, b, c);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  return 0;
}
