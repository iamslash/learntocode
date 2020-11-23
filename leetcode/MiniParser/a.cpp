/* Copyright (C) 2019 by iamslash */

#include <cstdio>

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
// 20ms 87.47% 15.7MB 76.06%
class Solution {
 private:
  int m_i = 0;
 public:
  NestedInteger solve(std::string& s) {
    if (s[m_i] == '[') {
      ++m_i;
      NestedInteger ni;
      while (s[m_i] != ']') {
        ni.add(solve(s));
        if (s[m_i] == ',')
          ++m_i;
      }
      ++m_i;
      return ni;
    } else {
      int num = 0;
      int sgn = 1;
      if (s[m_i] == '-') {
        sgn = -1;
        ++m_i;
      }
      while (std::isdigit(s[m_i])) {
        num *= 10;
        num += s[m_i++] - '0';
      }
      return NestedInteger(num * sgn);
    }
  }
  NestedInteger deserialize(std::string s) {
    return solve(s);
  }
};

// 12ms 99.76% 15.8MB 70.07%
// O(N) O(N)
class Solution {
 private:
  int m_i = 0;
 public:
  NestedInteger deserialize(std::string& s) {
    if (s[m_i] == '[') {
      ++m_i;
      NestedInteger ni;
      while (s[m_i] != ']') {
        ni.add(deserialize(s));
        if (s[m_i] == ',')
          ++m_i;
      }
      ++m_i;
      return ni;
    } else {
      int num = 0;
      int sgn = 1;
      if (s[m_i] == '-') {
        sgn = -1;
        ++m_i;
      }
      while (std::isdigit(s[m_i])) {
        num *= 10;
        num += s[m_i++] - '0';
      }
      return NestedInteger(num * sgn);
    }
  }
};


// [1,[2],3]
int main() {
  return 0;
}
