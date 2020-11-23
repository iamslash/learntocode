// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/TRAVERSAL

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int N;

// make slice vector from a to b of v
std::vector<int> slice(const std::vector<int>& v, int a, int b) {
  if (a >= v.size())
    return std::vector<int>();

  // printf("  ");
  // for (const int& i : v) {
  //   printf("%d ", i);
  // }
  // printf(" : %d, %d\n", a, b);

  std::vector<int> r = std::vector<int>(v.begin() + a, v.begin() + b);

  // printf("    ");
  // for (const int& i : r) {
  //   printf("%d ", i);
  // }
  // printf("\n");

  return r;
}

void Solve(const std::vector<int>& p_order, const std::vector<int>& i_order) {
  // base condition
  if (p_order.size() == 0)
    return;

  // recursion
  int root = p_order[0];
  auto it = std::find(i_order.begin(), i_order.end(), root);
  int cnt = it - i_order.begin();

  // 27, 3
  // printf("  %d %d\n", root, cnt);
  std::vector<int> p_order_l = slice(p_order, 1, cnt + 1);
  std::vector<int> p_order_r = slice(p_order, cnt + 1, p_order.size());
  std::vector<int> i_order_l = slice(i_order, 0, cnt);
  std::vector<int> i_order_r = slice(i_order, cnt + 1, i_order.size());

  Solve(p_order_l, i_order_l);
  Solve(p_order_r, i_order_r);
  printf("%d ", root);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
      scanf("%d", &N);
      std::vector<int> p_order(N);
      std::vector<int> i_order(N);
      for (int i = 0; i < N; ++i)
          scanf("%d", &p_order[i]);
      for (int i = 0; i < N; ++i)
          scanf("%d", &i_order[i]);
      Solve(p_order, i_order);
      printf("\n");
  }
  // std::vector<int> a(10);
  // std::vector<int> b = slice(a, 0, 1);
  // printf("%lu\n", b.size());

  return 0;
}

