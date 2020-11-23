// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/HABIT

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int N;

void print_v_int(const std::vector<int>& g) {
  // printf(" <----\n");
  for (int i=0; i < g.size(); ++i) {
    printf("%d ", g[i]);
  }
  // printf(" ---->\n");
}


std::vector<int> slice(const std::vector<int>& v, int a, int b) {
  return std::vector<int>(v.begin() + a, v.begin() + b);
}

void print_post_order(const std::vector<int>& v_porder,
                      const std::vector<int>& v_iorder) {
  // printf("%d %d\n", v_porder.size(), v_iorder.size());
  // base condition
  if (v_porder.size() == 0)
    return;

  // v_porder.size() 1보다 크다.
  int n_root = v_porder[0];
  auto it_root = std::find(v_iorder.begin(), v_iorder.end(), n_root);
  int n_lcnt = it_root - v_iorder.begin();
  // int n_rcnt = v_iorder.end() - it_root - 1;
  // printf("%d %d\n", n_lcnt, n_rcnt);

  std::vector<int> v_l_porder = slice(v_porder, 1, 1 + n_lcnt);
  std::vector<int> v_r_porder = slice(v_porder,
                                      1 + n_lcnt,
                                      v_porder.size());
  std::vector<int> v_l_iorder = slice(v_iorder, 0, n_lcnt);
  std::vector<int> v_r_iorder = slice(v_iorder,
                                      n_lcnt + 1,
                                      v_iorder.size());
  // printf("l ");
  // print_v_int(v_l_porder);
  // printf(" : ");
  // print_v_int(v_r_porder);
  // printf("\n");

  // recursion
  print_post_order(v_l_porder, v_l_iorder);
  print_post_order(v_r_porder, v_r_iorder);
  printf("%d ", n_root);
}

int main() {
  int T;
  std::cin >> T;

  for (int t = 0; t < T; ++t) {
    std::cin >> N;
    std::vector<int> v_pre_order(N);
    std::vector<int> v_in_order(N);

    int n;
    for (int i = 0; i < N; ++i) {
      std::cin >> v_pre_order[i];
    }
    for (int i = 0; i < N; ++i) {
      std::cin >> v_in_order[i];
    }

    print_post_order(v_pre_order, v_in_order);
    std::cout << std::endl;
  }
  //
  return 0;
}

// int main() {
//   std::vector<int> a;
//   // a.push_back(1);
//   std::vector<int> b(a.begin(), a.end());
//   std::cout << a.end() - a.begin() << std::endl;
//   return 0;
// }
