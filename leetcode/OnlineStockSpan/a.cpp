/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <stack>
#include <map>

// 100 80 60 70 60 75 85
//                     i
// 100 85
//   1  6

// 300ms 62.07% 71.5MB 72.94%
// O(N) O(N)
class StockSpanner {
 private:
  std::stack<std::pair<int, int>> m_stck;
 public:
  StockSpanner() {
    
  }
    
  int next(int price) {
    int ans  = 1;
    while (m_stck.size() && m_stck.top().first <= price) {
      ans += m_stck.top().second;
      m_stck.pop();
    }
    m_stck.push({price, ans});
    return ans;
  }
};


int main() {
  return 0;
}
