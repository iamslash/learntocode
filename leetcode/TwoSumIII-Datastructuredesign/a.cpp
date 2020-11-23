/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <map>
#include <unordered_set>

// 144ms 66.83% 23.8MB 61.90%
// Q. in case of method add, same number possible?
// Q. what is the range of num, val?
//  add: O(1) O(N)
// find: O(1) O(N)
class TwoSum {
  std::unordered_multiset<int> m_ust;
 public:
  TwoSum() {
  }
    
  void add(int num) {
    m_ust.insert(num);
  }
    
  bool find(int val) {
    for (int i : m_ust) {
      int cnt = i == val - i ? 1 : 0;
      if (m_ust.count(val - i) > cnt)
        return true;
    }
    return false;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  TwoSum sln;
  // sln.add(1);
  // sln.add(3);
  // sln.add(5);
  // printb(sln.find(4));
  // printb(sln.find(7));

  // sln.add(3);
  // sln.add(1);
  // sln.add(2);
  // printb(sln.find(3));
  // printb(sln.find(6));

  sln.add(0);
  sln.add(0);
  printb(sln.find(0));

  return 0;
}
