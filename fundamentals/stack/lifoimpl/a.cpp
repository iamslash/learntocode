/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

class MyStack {
 private:
  std::vector<int> m_data;
 public:
  void push(int x) {
    m_data.push_back(x);
  }
  bool isEmpty() {
    return m_data.empty();
  }
  int top() {
    if (isEmpty())
      return -1;
    return m_data.back();
  }
  bool pop() {
    if (isEmpty())
      return false;
    m_data.pop_back();
    return true;
  }
};

int main() {
  return 0;
}
