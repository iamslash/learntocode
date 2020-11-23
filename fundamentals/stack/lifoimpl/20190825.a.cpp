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
  bool isEmpty() {
    return m_data.empty();
  }
  int top() {
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
  MyStack s;
  s.push(1);
  s.push(2);
  s.push(3);
  for (int i = 0; i < 4; ++i) {
    if (!s.isEmpty()) {
      printf("%d\n", s.top());
    }
    printf("%s\n", s.pop() ? "true" : "false");
  }  
  return 0;
}
