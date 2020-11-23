/* Copyright (C) 2020 by iamslash */
#include <cstdio>
#include <vector>
#include <map>

using namespace std;
  
// append(2)      
// addAll(3)      
// append(7)
// multAll(2)
// getIndex(0)
// addAll(3)
// append(10)
// multiAll(2)
// getIndex(0)
// getIndex(1)
// getIndex(2)

//   A: 2 4
// inc: 3 
// mul: 1

// 688ms 40.65% 196.5MB 5.08%
// partial sum, modulo multiplicative inverse
// getIndex: O(1) O(N)
#define MOD 1000000007
class Fancy {
 private:
  uint64_t seq[100001];
  uint64_t len = 0;
  uint64_t inc = 0;
  uint64_t mul = 1;
  uint64_t modPow(uint64_t x, int y) {
    uint64_t all = 1, p = x;
    for (; y; y >>= 1) {
      if (y & 1) {
        all = (all * p) % MOD;
      }
      p = (p * p) % MOD;
    }
    return all;
  }
 public:
  Fancy() {
  }
    
  void append(int val) {
    seq[len++] = (((MOD + val - inc) % MOD) * modPow(mul, MOD - 2)) % MOD;
  }
    
  void addAll(int a) {
    inc = (inc + a % MOD) % MOD;
  }
    
  void multAll(int m) {
    mul = (mul * m % MOD) % MOD;
    inc = (inc * m % MOD) % MOD;
  }
    
  int getIndex(int i) {
    if (i >= len)
      return -1;
    return ((seq[i] * mul) % MOD + inc) % MOD;
  }
  void printMap(map<int, int>& M) {
    for (auto& pr : M) {
      printf("\tk: %d, v: %d\n", pr.first, pr.second);
    }
  }
};
