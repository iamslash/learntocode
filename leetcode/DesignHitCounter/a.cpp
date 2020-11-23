/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <deque>

// 8ms 47.77% 9.2MB 77.90%
// O(N) O(N)
class HitCounter {
 private:
  std::deque<int> m_cnter;
  void clean(int ts) {
    int i = ts - 300;
    while (m_cnter.size() && m_cnter.front() <= i) {
      m_cnter.pop_front();
    }
  }
 public:
    HitCounter() {
      
    }
    void hit(int ts) {
      m_cnter.push_back(ts);
      clean(ts);
    }
    int getHits(int ts) {
      clean(ts);
      return m_cnter.size();
    }
};

// ["HitCounter","hit","hit","hit","getHits","getHits","getHits","getHits","getHits","hit","getHits"]
// [[],[2],[3],[4],[300],[301],[302],[303],[304],[501],[600]]

int main() {
  HitCounter hc;
  hc.hit(2);
  hc.hit(3);
  hc.hit(4);
  printf("%d\n", hc.getHits(300));
  printf("%d\n", hc.getHits(301));
  printf("%d\n", hc.getHits(302));
  printf("%d\n", hc.getHits(303));
  printf("%d\n", hc.getHits(304));
  hc.hit(501);
  printf("%d\n", hc.getHits(600));
  
  return 0;
}
