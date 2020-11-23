// Copyright (C) 2017 by iamslash
// https://leetcode.com/problems/lru-cache/description/

// Design and implement a data structure for [Least Recently Used
// (LRU)
// cache](https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU). It
// should support the following operations: `get` and `put`.

// `get(key)` - Get the value (will always be positive) of the key if
// the key exists in the cache, otherwise return -1.
// `put(key, value)` - Set or insert the value if the key is not
// already present. When the cache reached its capacity, it should
// invalidate the least recently used item before inserting a new
// item.

// Follow up:
// Could you do both operations in **O(1)** time complexity?

// Example:
// ```LRUCache cache = new LRUCache( 2 /* capacity */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4```

#include <unordered_map>
#include <list>

class LRUCache {
 private:
  int m_capacity;
  std::unordered_map<int, std::pair<int, std::list<int>::iterator> > m_cache;
  std::list<int> m_used;
 public:
  LRUCache(int capacity) : m_capacity(capacity) {
    
  }
    
  int get(int key) {
    auto it = m_cache.find(key);
    if (it == m_cache.end())
      return -1;
    return it->second.first;
  }
    
  void put(int key, int value) {
    auto it = m_cache.find(key);
    if (it != m_cache.end()) {
      touch(it);
    } else {
      if (m_cache.size() == m_capacity) {
        m_cache.erase(m_used.back());
        m_used.pop_back();
      }
    }
    m_cache[key] = {value, m_used.begin()};
  }
  void touch(std::unordered_map<int, std::pair<int, std::list<int>::iterator>>::iterator it) {
    int key = it->first;
    m_used.erase(it->second.second);
    m_used.push_front(key);
    it->second.second = m_used.begin();
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main() {
  LRUCache cache(2);
  cache.put(1, 1);
  // cache.put(2, 2);
  // cache.get(1);       // returns 1
  // cache.put(3, 3);    // evicts key 2
  // cache.get(2);       // returns -1 (not found)
  // cache.put(4, 4);    // evicts key 1
  // cache.get(1);       // returns -1 (not found)
  // cache.get(3);       // returns 3
  // cache.get(4);       // returns 4```
  return 0;
}
