// Copyright (C) 2018 by iamslash
// https://www.geeksforgeeks.org/fractional-knapsack-problem/
// https://practice.geeksforgeeks.org/problems/fractional-knapsack/0

#include <cstdio>
#include <vector>
#include <algorithm>

int N = 3;
int C = 50;

class Item {
 public:
  int value;
  int weight;
  Item(int _value, int _weight) :
      value(_value), weight(_weight) {}  
};

int solve(std::vector<Item> v, int c, int n) {
  std::sort(v.begin(), v.end(),
            [](const Item& lhs, const Item& rhs) {
              double a = (double)lhs.value / lhs.weight;
              double b = (double)rhs.value / rhs.weight;
              return a > b;
            });
  int curw = 0;
  double r = 0.0;

  for (int i = 0; i < n; ++i) {
    if (curw + v[i].weight <= c) {
      curw += v[i].weight;
      r += v[i].value;
    } else {
      int remainw = c - curw;
      r += v[i].value * ((double)remainw / v[i].weight) ;
      break;
    }
  }
  
  return r;
}

int main() {
  std::vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
  printf("%d\n", solve(items, C, N));
  // 240  
  return 0;
}
