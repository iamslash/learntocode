/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <set>

// 44ms 38.22% 14MB 46.92%
//  seat: O(N)
// leave: O(lgN)
class ExamRoom {
 private:
  int m_n;
  std::set<int> m_sst;
 public:
  ExamRoom(int N) : m_n(N) {
    
  }
    
  int seat() {
    int student = 0;
    if (m_sst.size()) {
      int dist = *m_sst.begin();
      int prev = -1;
      for (int s : m_sst) {
        if (prev >= 0) {
          int d = (s - prev) / 2;
          if (d > dist) {
            dist = d;
            student = prev + d;
          }
        }
        prev = s;
      }
      if (m_n - 1 - *m_sst.rbegin() > dist)
        student = m_n - 1;
    }

    m_sst.insert(student);
    return student;
  }
    
  void leave(int student) {
    m_sst.erase(student);
  }
};


int main() {
  return 0;
}
