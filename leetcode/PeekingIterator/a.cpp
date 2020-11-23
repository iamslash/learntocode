/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 4ms 95.79% 10.4MB 5.63%
class Iterator {
  struct Data;
  Data* data;
 public:
  Iterator(const std::vector<int>& nums);
  Iterator(const Iterator& iter);
  virtual ~Iterator();
  int next();
  bool hasNext() const;
};

class PeekingIterator : public Iterator {
 public:
  PeekingIterator(const std::vector<int>& nums) :
      Iterator(nums) {
    
  }

  int peek() {
    return Iterator(*this).next();
  }

  int next() {
    return Iterator::next();
  }

  bool hasNext() const {
    return Iterator::hasNext();
  }
};

int main() {

  
  return 0;
}
