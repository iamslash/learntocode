#include <cstdio>
#include <list>
#include <set>
#include <map>
#include <vector>

// 108ms 72.56% 33.4MB 80.30%
class MaxStack {
 private:
  std::list<int> m_l;
  std::map<int, std::vector<std::list<int>::iterator>> m_smp;
 public:
  MaxStack() {
        
  }
    
  void push(int x) {
    m_l.push_front(x);
    m_smp[x].push_back(m_l.begin());
  }
    
  int pop() {
    int r = m_l.front();
    m_smp[r].pop_back();
    if (m_smp[r].empty())
      m_smp.erase(r);
    m_l.erase(m_l.begin());
    return r;
  }
    
  int top() {
    return m_l.front();      
  }
    
  int peekMax() {
    return m_smp.rbegin()->first;      
  }
    
  int popMax() {
    int r = peekMax();
    auto it = m_smp[r].back();
    m_smp[r].pop_back();
    if (m_smp[r].empty())
      m_smp.erase(r);
    m_l.erase(it);
    return r;
  }
};

int main() {
  MaxStack ms;
  ms.push(5);
  ms.push(5); 
  ms.push(1);
  ms.push(5);
  printf("%d\n", ms.top()); //-> 5
  printf("%d\n", ms.popMax()); //-> 5
  printf("%d\n", ms.top()); //-> 1
  printf("%d\n", ms.peekMax()); //-> 5
  printf("%d\n", ms.pop()); //-> 1
  printf("%d\n", ms.top()); //-> 5
  return 0;
}
