/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

// 96ms 99.15%
class MedianFinder {
 private:
  double m_median;
  std::priority_queue<int, std::vector<int>, std::less<int>> m_max_heap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> m_min_heap;
 public:
  /** initialize your data structure here. */
  MedianFinder() {
  }
    
  void addNum(int num) {
    if (m_max_heap.size() == m_min_heap.size())
      m_max_heap.push(num);
    else
      m_min_heap.push(num);
    // post process
    if (!m_max_heap.empty() && !m_min_heap.empty() &&
        m_max_heap.top() > m_min_heap.top()) {
      int a = m_max_heap.top(); m_max_heap.pop();
      int b = m_min_heap.top(); m_min_heap.pop();
      m_max_heap.push(b);
      m_min_heap.push(a);
    }
    if (m_max_heap.size() != m_min_heap.size())
      m_median = m_max_heap.top();
    else
      m_median = (m_max_heap.top() + m_min_heap.top())/2.0;
  }
    
  double findMedian() {
    return m_median;
  }
};

// 2 5 6 6 10
int main() {

  MedianFinder mf;
  mf.addNum(6);
  mf.addNum(10);
  mf.addNum(2);
  mf.addNum(6);
  mf.addNum(5);
  printf("%lf\n", mf.findMedian());
  
  return 0;
}
