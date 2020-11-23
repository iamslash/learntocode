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

// // Memory Limit exceeded
// class NestedIterator {
//  private:
//   std::vector<int> m_V;
//   std::vector<int>::const_iterator m_it;
//   void setValues(const std::vector<NestedInteger> &nl) {
//     for (const auto& ni : nl) {
//       if (ni.isInteger())
//         m_V.push_back(ni.getInteger());
//       else
//         setValues(ni.getList());
//     }
//   }
//  public:
//   NestedIterator(const std::vector<NestedInteger> &nl) {
//     // fill m_V
//     setValues(nl);
//     m_it = m_V.begin();
//   }

//   int next() {
//     return *m_it;
//   }

//   bool hasNext() {
//     if (m_it != m_V.end())
//       return true;
//     return false;
//   }
// };

// 12ms 99.24%
class NestedIterator {
 private:
  std::stack<std::vector<NestedInteger>::iterator> m_stck_b, m_stck_e;
 public:
  NestedIterator(std::vector<NestedInteger> &nl) {
    m_stck_b.push(nl.begin());
    m_stck_e.push(nl.end());
  }

  int next() {
    hasNext();
    return (m_stck_b.top()++)->getInteger();
  }

  int hasNext() {
    while (m_stck_b.size()) {
      if (m_stck_b.top() == m_stck_e.top()) {
        m_stck_b.pop();
        m_stck_e.pop();
      } else {
        auto it = m_stck_b.top();
        if (it->isInteger())
          return true;
        m_stck_b.top()++;
        m_stck_b.push(it->getList().begin());
        m_stck_e.push(it->getList().end());
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
  NestedIterator ni(V);
  while (ni.hasNext())
    printf("%d\n", ni.next());
  return 0;
}
