// Copyright (C) 2017 by iamslash

// Permutations without Dups: Write a method to compute all
// permutations of a string of unique characters.

// design : backtracking
// time complexity : O(n * n!)
// space complexity : O(1)

#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>

void print_indent(int indent) {
  for (int i = 0; i < indent; ++i)
    printf(" ");
}

void solve(int indent, char * s, int l, int r) {
  print_indent(indent);
  printf("%d %d\n", l , r);
  // base condition
  if (l == r - 1) {
    print_indent(indent);
    printf("%s\n", s);
  } else {
    for (int i = l; i < r; ++i) {
      std::swap(*(s + l), *(s + i));
      solve(indent + 1, s, l + 1, r);
      std::swap(*(s + l), *(s + i));
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    char buf[1024];
    scanf("%s", buf);
    solve(0, buf, 0, strlen(buf));
  }
  return 0;
}

