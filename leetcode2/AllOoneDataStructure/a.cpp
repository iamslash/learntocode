/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <string>

// 92ms 30.94% 26.6MB 55.56%
// hash map, bidirectional indexing
// O(1) O(N)
struct Bucket {
  int val;
  std::unordered_set<std::string> keys;
};
class AllOne {
 private:
  std::list<Bucket> buckets;
  std::unordered_map<std::string,
                     std::list<Bucket>::iterator> bucketByKey;
 public:
  void inc(std::string key) {
    // 0. enforce node of key
    if (bucketByKey.count(key) == 0)
      bucketByKey[key] = buckets.insert(buckets.begin(), {0, {key}});
    // 1. insert node and update the lookup
    auto u = bucketByKey[key], n = std::next(u);
    if (n == buckets.end() || u->val + 1 < n->val)
      n = buckets.insert(n, {u->val + 1, {}});
    n->keys.insert(key);
    bucketByKey[key] = n;
    // 2. remove node
    u->keys.erase(key);
    if (u->keys.empty())
      buckets.erase(u);
  }
    
  void dec(std::string key) {
    // 0. ensure key node
    if (bucketByKey.count(key) == 0)
      return;
    // 1. insert node and update the lookup
    auto u = bucketByKey[key], p = std::prev(u);
    bucketByKey.erase(key);
    if (u->val > 1) {
      if (u == buckets.begin() || p->val < u->val - 1)
        p = buckets.insert(u, {u->val-1, {}});
      p->keys.insert(key);
      bucketByKey[key] = p;
    }
    // 2. remove node
    u->keys.erase(key);
    if (u->keys.empty())
      buckets.erase(u);
  }
    
  std::string getMaxKey() {
    if (buckets.empty())
      return "";
    return *(buckets.rbegin()->keys.begin());
  }
    
  std::string getMinKey() {
    if (buckets.empty())
      return "";
    return *(buckets.begin()->keys.begin());
  }
};

