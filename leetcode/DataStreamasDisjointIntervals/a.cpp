/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

// 128ms 50.00% 24.2MB 0.85%
// addNum: O(1) O(N)
class SummaryRanges {
 private:
  std::map<int, int> m_smp;
  void merge(int val) {
    auto it = m_smp.find(val);
    auto left = std::prev(it, 1);
    if (left != m_smp.end() && (*left).second - (*it).first >= -1) {
      (*left).second = std::max((*it).second, (*left).second);
      m_smp.erase((*it).first);
      it = left;
    }
    auto right = std::next(it, 1);
    if (right != m_smp.end() && (*it).second - (*right).first >= -1) {
      (*it).second = std::max((*right).second, (*it).second);
      m_smp.erase((*right).first);
    }
  }
 public:
  SummaryRanges() {}
    
  void addNum(int val) {
    if (m_smp.count(val))
      return;
    if (m_smp.empty()) {
      m_smp[val] = val;
      return;
    }
    m_smp[val] = val;
    merge(val);
  }
    
  std::vector<Interval> getIntervals() {
    std::vector<Interval> rslt;
    for (auto& pr : m_smp)
      rslt.push_back({pr.first, pr.second});
    return rslt;
  }
};

int main() {
// [1, 1]
// [1, 1], [3, 3]
// [1, 1], [3, 3], [7, 7]
// [1, 3], [7, 7]
// [1, 3], [6, 7]
  std::vector<int> V = {1, 3, 7, 2, 6};
  SummaryRanges sr;
  for (int a : V) {
    sr.addNum(a);
    auto l = sr.getIntervals();
    for (auto intval : l)
      printf("(%d, %d) ", intval.start, intval.end);
    printf("\n");
  }
           
  return 0;
}
