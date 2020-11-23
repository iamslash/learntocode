/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <deque>

// class MyQueue {
//  private:
//   std::deque<int> m_data;
//  public:
//   bool enQueue(int a) {
//     m_data.push_back(a);
//     return true;
//   }
//   bool deQueue() {
//     if (isEmpty)
//       return false;
//     m_data.pop_front();
//     return true;
//   }
//   int front() {
//     return m_data.front();
//   }
//   bool isEmpty() {
//     return m_data.empty();
//   }
// };

class MyQueue {
 private:
  std::vector<int> m_data;
  int m_pos = 0;
 public:
  bool enQueue(int a) {
    m_data.push_back(a);
    return true;
  }
  bool deQueue() {
    if (isEmpty())
      return false;
    m_pos++;
    return true;
  }
  int front() {
    if (isEmpty())
      return -1;
    return m_data[m_pos];
  }
  int isEmpty() {
    return m_pos >= m_data.size();
  }
};

int main() {
  return 0;
}
