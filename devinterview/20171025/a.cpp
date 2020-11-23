// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <queue>
#include <vector>

class Solution {
 private:
 public:
  int solve(int N, int B, const std::vector<int>& a) {
    std::vector<int> load(a.size());  // m_load[i] = population / clinic
    std::vector<int> clinic(a.size(), 1);
    auto mycomp = [load](const int& idx1, const int& idx2) {
      return load[idx1] < load[idx2];
    };    
    std::priority_queue<int, std::vector<int>, decltype(mycomp)> pq(mycomp);

    for (int i = 0; i < a.size(); ++i) {
      load[i] = a[i] / clinic[i];      
      pq.push(i);
    }
    for (int i = 0; i < B - N; ++i) {
      // j is index of city which has the biggest load 
      int j = pq.top(); pq.pop();
      clinic[j] += 1;
      load[j] = a[j] / clinic[j];
      pq.push(j);
    }
    
    return load[pq.top()];
  }
};

int main() {
  Solution s;
  std::vector<int> v = {200000, 500000};
  printf("%d\n", s.solve(2, 7, v));
  return 0;
}
