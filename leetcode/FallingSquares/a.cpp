/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <tuple>


// 56ms 48.28% 10.7MB 80.95%
// O(N^2) O(N)
struct Event {
  int s;
  int e;
  int h;
  Event(int start, int end, int height) {
    s = start;
    e = end;
    h = height;
  }
};
class Solution {
 private:
  std::vector<Event> m_events;
  int getHeight(Event& evt) {
    int maxh = 0;
    for (auto a : m_events) {
      if (a.e <= evt.s ||
          a.s >= evt.e)
        continue;
      maxh = std::max(maxh, a.h);
    }
    evt.h += maxh;
    m_events.push_back(evt);
    return evt.h;
  }
 public:
  std::vector<int> fallingSquares(
      std::vector<std::pair<int, int>>& P) {
    std::vector<int> rslt;
    int maxh = 0;
    for (auto pr : P) {
      Event evt(pr.first, pr.first+pr.second, pr.second);
      maxh = std::max(maxh, getHeight(evt));
      rslt.push_back(maxh);
    }
    return rslt;
  }
};

int main() {

  std::vector<std::pair<int, int>> P = {
    {1, 2}, {2, 3}, {6, 1}    
  };
  Solution sln;
  auto rslt = sln.fallingSquares(P);
  for (int a : rslt)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
