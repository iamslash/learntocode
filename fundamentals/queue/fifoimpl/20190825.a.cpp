/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

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
    return m_data[m_pos];
  }
  int isEmpty() {
    return m_pos >= m_data.size();
  }
};

int main() {
  MyQueue q;
  q.enQueue(5);
  q.enQueue(3);
  if (!q.isEmpty())
    printf("%d\n", q.front());
  q.deQueue();
  if (!q.isEmpty())
    printf("%d\n", q.front());
  q.deQueue();
  if (!q.isEmpty())
    printf("%d\n", q.front());
  
  return 0;
}
