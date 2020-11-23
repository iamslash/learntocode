/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <map>

// ...................
//        10        :20
//                            50            :60
//        10              :40
//    5         :15
//    5   :10
//                      25         :55

// // 84ms 57.31%
// // O(N) O(N)
// class MyCalendarThree {
//  private:
//   std::map<int, int> m_sch;  // s : e
//  public:
//   MyCalendarThree() {
//   }
    
//   int book(int s, int e) {
//     int rst = 0;
//     int ing  = 0;
//     m_sch[s]++;
//     m_sch[e]--;
//     for (auto pr : m_sch) {
//       rst = std::max(rst, ing += pr.second);
//     }
//     return rst;
//   }
// };

// 52ms 91.61%
// O(N) O(N)
class MyCalendarThree {
 private:
  std::map<int, int> m_sch;
  int m_rst;
 public:
  MyCalendarThree() {
    m_sch = {{-1, 0}};
    m_rst = 0;
  }
  int book(int ns, int ne) {
    auto its = m_sch.emplace(ns, (--m_sch.lower_bound(ns))->second).first;
    auto ite = m_sch.emplace(ne, (--m_sch.lower_bound(ne))->second).first;
    for (auto it = its; it != ite; ++it)
      m_rst = std::max(m_rst, ++(it->second));
    return m_rst;
  }
};

//                24         :40
//                               43  :50
//                  27          :43
//   5         :21
//                      30   :40
//       14           :29
int main() {
  MyCalendarThree c;
  // printf("%d\n", c.book(10, 20));
  // printf("%d\n", c.book(50, 60));
  // printf("%d\n", c.book(10, 40));
  // printf("%d\n", c.book(5, 15));
  // printf("%d\n", c.book(5, 10));
  // printf("%d\n", c.book(25, 55));
  printf("%d\n", c.book(24, 40)); // 1
  printf("%d\n", c.book(43, 50)); // 1
  printf("%d\n", c.book(27, 43)); // 2
  printf("%d\n", c.book(5, 21));  // 2
  printf("%d\n", c.book(30, 40)); // 3
  printf("%d\n", c.book(14, 29)); // 3
  
  return 0;
}
