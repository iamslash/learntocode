/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <cstdlib>
#include <vector>

class NumArray {
 private:
  std::vector<int> m_tree;
  int sum(int pos) {
    ++pos;
    int rslt = 0;
    while (pos > 0) {
      rslt += m_tree[pos];
      pos &= (pos - 1);
    }
    return rslt;
  }
  void add(int pos, int val) {
    ++pos;
    while (pos < m_tree.size()) {
      m_tree[pos] += val;
      pos += (pos & -pos);
    }
  }
  
 public:
  NumArray(std::vector<int> V) {
    int n = V.size();
    m_tree = std::vector<int>(n+1, 0);
    for (int i = 0; i < n; ++i)
      add(i, V[i]);
  }
    
  void update(int i, int val) {
    int org = sum(i);
    if (i > 0)
      org -= sum(i-1);
    add(i, val - org);
  }
    
  int sumRange(int i, int j) {
    int rslt = sum(j);
    if (i > 0)
      rslt -= sum(i-1);
    return rslt;
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

int main() {

  std::vector<int> V = {1, 3, 5};
  
  NumArray na(V);
  printf("%d\n", na.sumRange(0, 2));
  na.update(1, 2);
  printf("%d\n", na.sumRange(0, 2));
  
  return 0;
}
