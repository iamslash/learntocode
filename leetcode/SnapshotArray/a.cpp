/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>

// 268ms 84.00% 79.3MB 100.00%
// binary search
// get: O(lgN)
class SnapshotArray {
 private:
  std::unordered_map<int, std::map<int, int>> m_shot;
  int m_shotid = 0;
 public:
  explicit SnapshotArray(int len) {
  }

  void set(int dataid, int val) {
    m_shot[dataid][m_shotid] = val;
  }

  int snap() {
    return ++m_shotid;
  }

  int get(int dataid, int shotid) {
    auto it = m_shot[dataid].upper_bound(shotid);
    return it == m_shot[dataid].begin() ? 0 :
        std::prev(it)->second;
  }
};

int main() {
  return 0;
}
