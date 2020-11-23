/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

class MyCircularQueue {
 private:
  int m_capa;
  int m_size;
  int m_head;
  int m_tail;
  std::vector<int> m_v;
public:
    MyCircularQueue(int k) {
      m_v = std::vector<int>(k);
      m_capa = k;
      m_head = 0;
      m_tail = 0;
      m_size = 0;
    }
    
    bool enQueue(int val) {
      if (isFull())
        return false;        
      m_tail = ++m_tail % m_capa;
      m_v[m_tail] = val;
      if (isEmpty())
        m_head = m_tail;        
      m_size++;
      return true;
    }
    
    bool deQueue() {
      if (isEmpty())
        return false;
      m_head = ++m_head % m_capa;
      m_size--;
      return true;        
    }
    
    int Front() {
      if (isEmpty())
        return -1;
      return m_v[m_head];
    }
    
    int Rear() {
      if (isEmpty())
        return -1;
      return m_v[m_tail];
    }
    
    bool isEmpty() {
      return m_size == 0;
    }
    
    bool isFull() {
      return m_size == m_capa;        
    }
};


int main() {

  MyCircularQueue circularQueue(3); // set the size to be 3
  circularQueue.enQueue(1);  // return true
  circularQueue.enQueue(2);  // return true
  circularQueue.enQueue(3);  // return true
  circularQueue.enQueue(4);  // return false, the queue is full
  circularQueue.Rear();  // return 3
  circularQueue.isFull();  // return true
  circularQueue.deQueue();  // return true
  circularQueue.enQueue(4);  // return true
  circularQueue.Rear();  // return 4
  
  return 0;
}
