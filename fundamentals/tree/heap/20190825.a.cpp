/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>


//      1
//    /   \
//   6     8
//  
// 

class MyHeap {
 private:
  std::vector<int> m_data;
 public:
  void push(int a) {
    m_data.push_back(a);
    int i = m_data.size() - 1;
    while (i > 0 && m_data[i] > m_data[(i-1)/2]) {
      std::swap(m_data[i], m_data[(i-1)/2]);
    }
  }
  int pop() {
    int t = m_data[0];
    m_data[0] = m_data.back();
    m_data.pop_back();
    int u = 0;
    while (true) {
      int l = u*2 + 1;
      int r = u*2 + 2;
      if (l >= m_data.size())
        break;
      int v = u;
      if (m_data[v] < m_data[l])
        v = l;
      if (r < m_data.size() && m_data[v] < m_data[r])
        v = r;
      if (v == u)
        break;
      std::swap(m_data[u], m_data[v]);
      u = v;
    }
    return t;
  }
};

int main() {
  MyHeap heap;
  heap.push(8);
  heap.push(8);
  heap.push(7);
  heap.push(6);
  heap.push(6);
  heap.push(6);
  heap.push(6);
  heap.push(6);
  heap.push(5);

  printf("%d\n", heap.pop());
  
  return 0;
}
