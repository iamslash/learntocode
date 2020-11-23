/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <unordered_map>
#include <map>

// 432ms 32.29% 136.7MB 43.75%
class TimeMap {
 private:
  std::unordered_map<std::string, std::map<int, std::string>> m_smp;
 public:
  /** Initialize your data structure here. */
  TimeMap() {
    
  }
    
  void set(std::string key, std::string val, int ts) {
    m_smp[key][ts] = val;
  }
    
  std::string get(std::string key, int ts) {
    if (m_smp.count(key) == 0)
      return "";
    auto& smp = m_smp[key];
    if (smp.size() == 0)
      return "";
    auto   it = smp.upper_bound(ts);
    if (it == smp.begin())
      return "";
    it = std::prev(it);
    return it->second;
  }
};

int main() {
  return 0;
}
