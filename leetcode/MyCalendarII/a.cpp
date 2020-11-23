/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>

// // 120ms 86.61% 32.2MB 80.90%
// // brute force
// // O(N^2) O(N)
// class MyCalendarTwo {
//  private:
//   std::vector<std::pair<int, int>> m_cal;
//   std::vector<std::pair<int, int>> m_dup;
//  public:
//   MyCalendarTwo() {}
    
//   bool book(int s, int e) {
//     for (auto& cal : m_dup) {
//       int x = cal.first;
//       int y = cal.second;
//       if (x < e && s < y)
//         return false;
//     }
//     for (auto& cal : m_cal) {
//       int x = cal.first;
//       int y = cal.second;
//       if (x < e && s < y)
//         m_dup.push_back({std::max(x, s), std::min(y, e)});
//     }
//     m_cal.push_back({s, e});
//     return true;
//   }
// };

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  MyCalendarTwo mct;
  printb(mct.book(10, 20));
  printb(mct.book(50, 60));
  printb(mct.book(10, 40));
  printb(mct.book(5, 15));
  printb(mct.book(5, 10));
  printb(mct.book(25, 55));
  
  return 0;
}
