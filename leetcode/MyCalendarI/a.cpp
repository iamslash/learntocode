/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>

// // 148ms 49.04% 35.4MB 69.05%
// // O(N) O(N)
// class MyCalendar {
//  private:
//     std::vector<std::pair<int, int>> m_sch;
//  public:
//   MyCalendar() {}    
//   bool book(int s, int e) {
//     for (auto& pr : m_sch) {
//       int x = pr.first;
//       int y = pr.second;
//       if (std::max(x, s) < std::min(y, e))
//         return false;
//     }
//     m_sch.push_back({s,e});
//     return true;
//   }
// };

// 112ms 99.76% 36.5MB 24.60%
// map
// O(lgN) O(N)
class MyCalendar {
 private:
  std::map<int, int> m_smp;
 public:
  MyCalendar() {}
  bool book(int s, int e) {
    auto it = m_smp.lower_bound(s);
    int x = it->first;
    int y = it->second;
    printf("[%d,%d] [%d,%d]\n", x, y, s, e);
    if (it != m_smp.end() && e > it->first)
      return false;
    if (it != m_smp.begin() && s < (--it)->second)
      return false;
    m_smp[s] = e;
    return true;
  }
};

// // BST
// // O(lgN) O(N)
// class MyCalendar {
//  public:
//   MyCalendar() {}
//   bool book(int s, int e) {

//   }
// };

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  MyCalendar mc;
  printb(mc.book(10, 20));
  printb(mc.book(15, 25));
  // printb(mc.book(20, 30));


  // {
  //   std::map<int, int> smp;
  //   // smp[10] = 20;
  //   auto it = smp.lower_bound(10);
  //   printb(smp.begin() == smp.end());
  //   // printf("%d %d\n", (it)->first, (it)->second);
  // }
  
  return 0;
}
