/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>

// 48ms 2.55%
// 15MB 0.00%
class MyCircularDeque {
 private:
  int m_head;
  int m_tail;
  int m_size;
  int m_capa;
  std::vector<int> m_core;
 public:
  MyCircularDeque(int k) {
    m_head = k-1;
    m_tail = m_size = 0;
    m_capa = k;
    m_core = std::vector<int>(k);
  }
  bool insertFront(int val) {
    if (isFull())
      return false;
    m_core[m_head] = val;
    ++m_size;
    m_head = (m_head - 1 + m_capa) % m_capa;
    return true;
  }
    
  bool insertLast(int val) {
    if (isFull())
      return false;
    m_core[m_tail] = val;
    ++m_size;
    m_tail = (m_tail + 1) % m_capa;
    return true;
  }
    
  bool deleteFront() {
    if (isEmpty())
      return false;
    m_head = (m_head + 1) % m_capa;
    --m_size;
    return true;
  }
    
  bool deleteLast() {
    if (isEmpty())
      return false;    
    m_tail = (m_tail - 1 + m_capa) % m_capa;
    --m_size;
    return true;
  }
    
  int getFront() {
    if (isEmpty())
      return -1;
    int idx = (m_head + 1) % m_capa;
    return m_core[idx];        
  }
  
  int getRear() {
    if (isEmpty())
      return -1;
    int idx = (m_tail - 1 + m_capa) % m_capa;
    return m_core[idx];
  }
    
  bool isEmpty() {
    return m_size == 0;    
  }
    
  bool isFull() {
    return m_size == m_capa;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

void printi(int i) {
  printf("%d\n", i);
}

int main() {
  // MyCircularDeque dq(3);
  // printb(dq.insertLast(1));
  // printb(dq.insertLast(2));
  // printb(dq.insertFront(3));
  // printb(dq.insertFront(4));
  // printi(dq.getRear());
  // printb(dq.isFull());
  // printb(dq.deleteLast());
  // printb(dq.insertFront(4));
  // printi(dq.getFront());

  MyCircularDeque dq(5);
  printb(dq.insertFront(7));
  printb(dq.insertLast(0));
  printi(dq.getFront());
  
  return 0;
}
