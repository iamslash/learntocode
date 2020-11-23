/* Copyright (C) 2019 by iamslash */

#include <cstdio>

class MyQueue {
 private:
  std::vector<int> m_data;
  int m_pos;
 public:
  MyQueue() { m_pos = 0; }
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
  bool isEmpty() {
    return m_pos >= m_data.size();
  }
};


int main() {
  return 0;
}
