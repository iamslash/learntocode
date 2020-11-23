// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/QUADTREE

#include <cstdio>
#include <string>

std::string reverse(std::string::iterator & it) {
  char c = *it;
  it++;

  // base condition
  if (c == 'w' || c == 'b')
    return std::string(1, c);

  // recursion
  std::string lt = reverse(it);
  std::string rt = reverse(it);
  std::string lb = reverse(it);
  std::string rb = reverse(it);
  return "x" + lb + rb + lt + rt;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    char buf[1024];
    scanf("%s", buf);
    std::string s = buf;
    std::string::iterator it = s.begin();
    printf("%s\n", reverse(it).c_str());
  }
  return 0;
}

