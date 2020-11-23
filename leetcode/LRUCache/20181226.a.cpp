/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <vector>
#include <list>

// 72ms 53.37%
#include <iostream>
int __ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();
class LRUCache {
 private:
  int m_cap;
  // (key, (val, it of m_H))
  std::unordered_map<int, std::pair<int, std::list<int>::iterator>> m_C; 
  std::list<int> m_H; // history of it

 private:
  void touch(int key) {
    // del it
    int val = m_C[key].first;
    auto it = m_C[key].second;
    m_H.erase(it);
    m_H.push_back(key);
    it = std::prev(m_H.end());
    m_C[key] = {val, it};
  }
  void shrink() {
    if (m_C.size() < m_cap)
      return;
    int key = m_H.front();
    m_H.erase(m_H.begin());
    m_C.erase(key);
  }
 public:
  LRUCache(int cap) : m_cap(cap) {}
    
  int get(int key) {
    if (m_C.count(key) == 0)
      return -1;
    touch(key);
    return m_C[key].first;
  }
  
  void put(int key, int val) {
    if (m_C.count(key) == 0) {
      shrink();
      m_H.push_back(key);
      auto it = std::prev(m_H.end());
      m_C[key] = {val, it};
    } else {
      m_C[key].first = val;
      touch(key);
    }
  }

  void dump_H() {
    for (int key : m_H) {
      printf("%d ", key);
    }
    printf("\n");
  }
};

// // 116ms 12.52%
// class LRUCache {
//  private:
//   const int m_cap;
//   std::list<std::pair<int, int>> m_H;
//   std::unordered_map<int, std::list<std::pair<int, int>>::const_iterator> m_C;
//  public:
//   LRUCache(int cap) : m_cap(cap) {}
//   int get(int key) {
//     auto it = m_C.find(key);
//     if (it == m_C.end())
//       return -1;
//     int val = it->second->second;
//     m_H.erase(it->second);
//     m_H.emplace_front(key, val);
//     it->second = m_H.cbegin();
//     return val;
//   }

//   void put(int key, int val) {
//     auto it = m_C.find(key);
//     if (it != m_C.end()) {
//       m_H.erase(it->second);
//     } else if (m_C.size() == m_cap) {
//       m_C.erase(m_H.back().first);
//       m_H.pop_back();
//     }
//     m_H.emplace_front(key, val);
//     m_C[key] = m_H.cbegin();
//   }
// };

int main() {

  LRUCache C(2);
  C.put(1, 1);
  C.put(2, 2);
  printf("%d\n", C.get(1));
  C.put(3, 3);
  printf("%d\n", C.get(2));
  // C.dump_H(); 
  C.put(4, 4);
  printf("%d\n", C.get(1));
  printf("%d\n", C.get(3));
  printf("%d\n", C.get(4));
  
  return 0;
}
