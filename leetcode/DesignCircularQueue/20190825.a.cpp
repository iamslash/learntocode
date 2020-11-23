/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 40ms 9.06%
// 15MB 0.85%
class MyCircularQueue {
 private:
  int m_capa;
  int m_size;
  int m_head;
  int m_tail;
  std::vector<int> m_v;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
      m_v = std::vector<int>(k);
      m_capa = k;
      m_head = 0;
      m_tail = 0;
      m_size = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
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
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
      if (isEmpty())
        return false;
      m_head = ++m_head % m_capa;
      m_size--;
      return true;        
    }
    
    /** Get the front item from the queue. */
    int Front() {
      if (isEmpty())
        return -1;
      return m_v[m_head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
      if (isEmpty())
        return -1;
      return m_v[m_tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
      return m_size == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
      return m_size == m_capa;        
    }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

void printi(int n) {
  printf("%d\n", n);
}

int main() {
  // MyCircularQueue q(3);
  // printb(q.enQueue(1));
  // printb(q.enQueue(2));
  // printb(q.enQueue(3));
  // printb(q.enQueue(4));
  // printi(q.Rear());
  // printb(q.isFull());
  // printb(q.deQueue());
  // printb(q.enQueue(4));
  // printi(q.Rear());

  MyCircularQueue q(3);
  printb(q.enQueue(2));
  printi(q.Rear());
  printi(q.Front()); 
  
  return 0;
}
