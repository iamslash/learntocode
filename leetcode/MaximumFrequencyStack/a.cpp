/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <stack>
#include <unordered_map>
#include <map>

// // 156ms 19.23%
// // O(1) O(N)
// class FreqStack {
//  private:
//   int m_maxfreq;
//   std::unordered_map<int, int> m_ump_num2freq;
//   std::unordered_map<int, std::stack<int>> m_ump_freq2stck;
//  public:
//   FreqStack() {
    
//   }
    
//   void push(int x) {
//     m_ump_num2freq[x]++;
//     m_maxfreq = std::max(m_maxfreq, m_ump_num2freq[x]);
//     m_ump_freq2stck[m_ump_num2freq[x]].push(x);
//   }
    
//   int pop() {
//     int num = m_ump_freq2stck[m_maxfreq].top();
//     m_ump_freq2stck[m_maxfreq].pop();
//     if (m_ump_freq2stck[m_maxfreq].empty())
//       m_maxfreq--;
//     m_ump_num2freq[num]--;
//     return num;
    
//   }
// };

// 136ms 75.64%
// O(1) O(N)
class FreqStack {
 private:
  std::map<int, std::stack<int>, std::greater<int>> m_freq2stck;
  std::unordered_map<int, int> m_num2freq;
 public:
  FreqStack() {}
  void push(int x) {
    m_freq2stck[++m_num2freq[x]].push(x);
  }
  int pop() {
    std::stack<int>& stck = m_freq2stck.begin()->second;
    int num = stck.top(); stck.pop();
    if (stck.empty())
      m_freq2stck.erase(m_freq2stck.begin());
    --m_num2freq[num];
    return num;                         
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */

int main() {
  FreqStack fstck;
  fstck.push(5);
  fstck.push(7);
  fstck.push(5);
  fstck.push(7);
  fstck.push(4);
  fstck.push(5);
  for (int i = 0; i < 4; ++i)
    printf("%d\n", fstck.pop());
  
  return 0;
}
