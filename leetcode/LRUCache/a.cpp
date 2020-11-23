/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <list>

// 88ms 42.41%
// O(N) O(1)
class LRUCache {
 private:
  int m_cap;
  std::unordered_map<int, std::pair<int, std::list<int>::iterator>> m_C;
  std::list<int> m_H;
 public:
  LRUCache(int cap) : m_cap(cap) {}
    
  int get(int key) {
    if (m_C.count(key) == 0)
      return -1;
    // touch history
    int val = m_C[key].first;
    auto it = m_C[key].second;
    m_H.erase(it);
    m_H.push_back(key);
    m_C[key] = {val, std::prev(m_H.end())};
    return val;
  }
    
  void put(int key, int val) {
    if (m_C.count(key) == 0) {
      // check cpacity
      if (m_C.size() == m_cap) {
        int old_key = *m_H.begin();
        m_H.pop_front();
        m_C.erase(old_key);
      }
    } else {
      // touch history
      auto it = m_C[key].second;
      m_H.erase(it);
    }
    m_H.push_back(key);
    m_C[key] = {val, std::prev(m_H.end())};
  }
  
  void dump_H() {
    for (int key : m_H) {
      printf("%d ", key);
    }
    printf("\n");
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main() {
  LRUCache c(1);
  // c.dump_H();

  return 0;
}
