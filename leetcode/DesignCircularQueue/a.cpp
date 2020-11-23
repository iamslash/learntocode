/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 36ms 49.85% 16.4MB 90.91%
class MyCircularQueue {
 private:
  std::vector<int> m_data;
  int m_capa;
  int m_size;
  int m_head;
  int m_tail;
 public:
  MyCircularQueue(int k) {
    m_data.resize(k);
    m_capa = k;
    m_size = 0;
    m_head = 0;
    m_tail = k-1;
  }
    
  bool enQueue(int val) {
    if (isFull())
      return false;
    m_size++;
    m_tail = (m_tail + 1) % m_capa;
    m_data[m_tail] = val;
    return true;
  }
    
  bool deQueue() {
    if (isEmpty())
      return false;
    m_size--;
    m_head = (m_head + 1) % m_capa;
    return true;
  }
    
  int Front() {
    if (isEmpty())
      return -1;
    return m_data[m_head];
  }
    
  int Rear() {
    if (isEmpty())
      return -1;
    return m_data[m_tail];
  }
    
  bool isEmpty() {
    return m_size == 0;
  }
    
  bool isFull() {
    return m_size >= m_capa;
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {

  MyCircularQueue q(10);
  bool b1 = q.enQueue(3);
  bool b2 = q.deQueue();
  int  n3 = q.Front();
  int  n4 = q.Rear();
  bool b5 = q.isEmpty();
  bool b6 = q.isFull();
  
  return 0;
}
