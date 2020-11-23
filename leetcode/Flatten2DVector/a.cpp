/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 56ms 98.33% 22.9MB 89.80%
// O(N) O(1)
class Vector2D {
 private:
  int i = 0;
  std::vector<int> m_V;
 public:
  Vector2D(std::vector<std::vector<int>>& V) {
    for (int i = 0 ; i < V.size(); ++i) {
      for (int a : V[i])
        m_V.push_back(a);
    }
    i = 0;
  }
    
  int next() {
    return m_V[i++];
  }
    
  bool hasNext() {
    return i < m_V.size();
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}
void printn(int n) {
  printf("%d\n", n);
}

int main() {
  std::vector<std::vector<int>> V = {{1,2},{3},{4}};

  Vector2D iterator(V);
  printn(iterator.next()); // return 1
  printn(iterator.next()); // return 2
  printn(iterator.next()); // return 3
  printb(iterator.hasNext()); // return true
  printb(iterator.hasNext()); // return true
  printn(iterator.next()); // return 4
  printb(iterator.hasNext()); // return false

  return 0;
}
