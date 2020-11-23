/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <map>

using namespace std;

//        i
// data: 10 
//       20 
//
// addRange(10, 20)
// addRange(1, 5)

// 416ms 88.50% 70.5MB 88.79%
class RangeModule {
 private:
  map<int, int, greater<int>> data;
 public:
  void addRange(int left, int right) {
    for (auto it = data.lower_bound(right); it != data.end() && it->second >= left;) {
      left = min(left, it->first);
      right = max(right, it->second);
      it++;
      data.erase(prev(it));
    }
    data[left] = right;
  }
    
  bool queryRange(int left, int right) {
    auto it = data.lower_bound(left);
    if (it == data.end()) {
      return false;
    }
    return right <= it->second;
  }
    
  void removeRange(int left, int right) {
    for (auto it = data.upper_bound(right); it != data.end() && it->second > left;) {
      auto jt = next(it);
      if (it->second > right) {
        data[right] = it->second;
      }
      if (it->first < left) {
        it->second = left;
      } else {
        data.erase(it);
      }
      it = jt;
    }
  }
};
