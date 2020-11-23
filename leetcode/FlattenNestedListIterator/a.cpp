/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <stack>

class NestedInteger {
 public:
  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  std::vector<NestedInteger> &getList() const;
};

// 
// [[1,1],2,[1,1]]
//        b
//               e
//   b
//      e
//
// 16ms 48.22%
class NestedIterator {
 private:
  std::stack<std::vector<NestedInteger>::iterator> m_stck_b, m_stck_e;
 public:
  NestedIterator(std::vector<NestedInteger> &nestedList) {
    m_stck_b.push(nestedList.begin());
    m_stck_e.push(nestedList.end());
  }

  int next() {
    hasNext();
    return (m_stck_b.top()++)->getInteger();
  }

  // forward until find integer value
  bool hasNext() {
    while (m_stck_b.size()) {
      if (m_stck_b.top() == m_stck_e.top()) {
        m_stck_b.pop();
        m_stck_e.pop();
      } else {
        auto it = m_stck_b.top();
        if (it->isInteger()) {
          return true;
        } else {
          m_stck_b.top()++;
          m_stck_b.push(it->getList().begin());
          m_stck_e.push(it->getList().end());
        }
      }
    }
    return false;
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
  std::vector<NestedInteger> V;
  NestedIterator nit(V);
  while (nit.hasNext())
    printf("%d ", nit.next());
  printf("\n");
  
  return 0;
}
