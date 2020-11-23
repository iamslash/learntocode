// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/NERD2

#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int N;

void print_m_int_int(const std::map<int, int>& m) {
  for (auto it = m.cbegin(); it != m.cend(); ++it) {
    printf("[%4d : %4d] ", it->first, it->second);
  }
  printf("\n");
}

bool is_dominated(const std::map<int, int>& m, int x, int y) {
  // 
  if (m.empty())
    return false;

  // x보다 크면서 최소인 것을 찾아라. 
  auto it = m.lower_bound(x);
  it++;
  if (it == m.end())
    return false;
  //
  if (it->second > y)
    return false;
  
  return true;
}

void del_dominated(std::map<int, int>& m, int x, int y) {
  auto it = m.upper_bound(x);
  if (it == m.end())  // 해당하는 녀석이 없다면 중지
    return;
  std::vector<int> v;
  //
  while (it != m.begin()) {
    if (it->first < x && it->second < y)
      v.push_back(it->first);      
    it--;
  }
  // remove all
  std::for_each(v.begin(), v.end(),
                [&m](int a)
                {
                  m.erase(m.find(a));
                });  
}

int reg_cand(std::map<int, int>& m, int x, int y) {
  // 새로운 참가자는 기존의 참가자들에게 점유되는가???
  if (is_dominated(m, x, y))
    return m.size();
  // 새로운 참가자에게 점유되는 기존의 참가자들을 제거하자.
  del_dominated(m, x, y);
  // 새로운 참가자는 추가되야 한다.
  m[x] = y;
  return m.size();
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);

    std::map<int, int> m;
    int x, y, r = 0;
    for (int i = 0; i < N; ++i) {
      scanf("%d %d", &x, &y);
      r += reg_cand(m, x, y);
    }
    printf("%d\n", r);
  }
  

  // std::vector<int> v = {0, 1, 2, 3, 4, 5};
  // printf("%d\n", *std::lower_bound(v.begin(), v.end(), 3));
  // printf("%d\n", *std::upper_bound(v.begin(), v.end(), 3));

  return 0;
}
