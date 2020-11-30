/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <deque>

using namespace std;

// 52ms 100.00% 21.1MB 100.00%
// double deque
// O(1) O(N)
class FrontMiddleBackQueue {
 private:
  deque<int> a, b;
  // move if there is something to balance from a to b
  void balanceA2B() {
    if (a.size() <= b.size())
      return;
    b.push_front(a.back());
    a.pop_back();
  }
  // move if there is something to balance from b to a
  void balanceB2A() {
    if (b.size() <= a.size() + 1)
      return;
    a.push_back(b.front());
    b.pop_front();
  }
 public:
  FrontMiddleBackQueue() {
    
  }
    
  void pushFront(int val) {
    a.push_front(val);
    balanceA2B();
  }
    
  void pushMiddle(int val) {
    a.push_back(val);
    balanceA2B();        
  }
    
  void pushBack(int val) {
    b.push_back(val);
    balanceB2A();
  }
    
  int popFront() {
    if (a.empty() && b.empty())
      return -1;
    int ans;
    if (a.empty()) {
      ans = b.front();
      b.pop_front();
    } else {
      ans = a.front();
      a.pop_front();
      balanceB2A();
    }
    return ans;
  }
    
  int popMiddle() {
    if (a.empty() && b.empty())
      return -1;
    int ans;
    if (a.size() == b.size()) {
      ans = a.back();
      a.pop_back();
    } else {
      ans = b.front();
      b.pop_front();
    }
    return ans;
  }
    
  int popBack() {
    if (a.empty() && b.empty())
      return -1;
    int ans = b.back();
    b.pop_back();
    balanceA2B();
    return ans;
  }
};

