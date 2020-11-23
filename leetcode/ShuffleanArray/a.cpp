/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// 1 2 3
// 324ms 4.81%
class Solution {
 private:
  std::vector<int> m_V;
  unsigned int m_seed;
 public:
  Solution(const std::vector<int>& V) {
    m_V = V;
  }
    
  /** Resets the array to its original configuration and return it. */
  std::vector<int> reset() {
    return m_V;
  }
    
  /** Returns a random shuffling of the array. */
  std::vector<int> shuffle() {
    std::vector<int> R(m_V);
    for (int i = 0; i < R.size(); ++i) {
      int pos = std::rand() % (R.size() - i);
      std::swap(R[i+pos], R[i]);
    }    
    return R;
  }
};

void printv(const std::vector<int>& V) {
  for (int a : V)
    printf("%d ", a);
  printf("\n");  
}
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
int main() {

  std::vector<int> V = {1, 2, 3};
  printv(V);
  
  Solution sln(V);
  V = sln.shuffle();
  printv(V);  
  
  V = sln.reset();
  printv(V);  
  
  V = sln.shuffle();  
  printv(V);  

  return 0;
}
