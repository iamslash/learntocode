/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

// 1 3 0 1 2  5  4   8  
// 1 3 0 1 2 10 40 320

// 388ms 18.37% 70MB 100.00%
// partial product
// getProduct: O(1) O(N)
class ProductOfNumbers {
 private:
  vector<int> pp = {1};
 public:
  ProductOfNumbers() {
        
  }
    
  void add(int num) {
    if (num == 0) {
      pp = {1};
      return;
    }
    pp.push_back(pp.back() * num);
  }
    
  int getProduct(int k) {
    int i = (int)pp.size() - k - 1;
    if (i < 0)
      return 0;
    return pp.back() / pp[i];
  }
};
