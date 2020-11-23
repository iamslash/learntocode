/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

class MyStack {
 private:
  std::vector<int> m_data;
 public:
  void push(int a) {
    m_data.push_back(a);
  }
  void pop() {
    if (isEmpty())
      return;
    m_data.pop_back();
  }
  int top() {
    if (isEmpty())
      return -1;
    return m_data.back();
  }
  bool isEmpty() {
    return m_data.empty();
  }

};

int main() {
  return 0;
}
