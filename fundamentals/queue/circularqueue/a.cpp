/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

class MyCircularQueue {
 private:
  std::vector<int> m_data;
  int m_capa;
  int m_size;
  int m_head;
  int m_tail;
  
 public:
    MyCircularQueue(int k) {
      m_data = std::vector<int>(k);
      m_capa = k;
      m_size = 0;
      m_head = 0;
      m_tail = k-1;
    }
    bool enQueue(int val) {
      if (isFull())
        return false;
      m_tail = (m_tail + 1) % m_size;
      m_data[m_tail] = val;
      m_size++;
      return true;
    }
    bool deQueue() {
      if (isEmpty()) {
        m_head = m_tail;
        return false;
      }
      m_head = (m_head + 1) % m_size;
      m_size--;
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
      return m_size == m_capa;
    }
};

int main() {
  return 0;
}
