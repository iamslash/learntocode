// Copyright (C) 2017 by iamslash

// Permutations with Duplicates: Write a method to compute all
// permutations of a string whose characters are not necessarily
// unique. The list of permutations should not have duplicates.

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>

// ex) ABA
// AAB
// AAB     BAA
// AAB ABA BAA

int N;
std::set<std::string> ST;

void print_indent(int indent) {
  for (int i = 0; i < indent; ++i)
    printf(" ");
}

// void solve(int indent, std::string s, int l) {
//   // print_indent(indent);
//   // printf("%d\n", l);
//   // base condition
//   if (l == N - 1) {
//     // print_indent(indent);
//     printf("%s\n", s.c_str());
//     return;
//   }
//   std::sort(s.begin() + l, s.end());
//   // recursion
//   for (int i = l; i < N; ++i) {
//     if (i == 0 || (i > 0 && s[i-1] != s[i])) {
//       std::swap(s[l], s[i]);
//       solve(indent + 1, s, l + 1);
//       std::swap(s[l], s[i]);
//     }
//   }
// }

void solve(int indent, std::string s, int l) {
  // print_indent(indent);
  // printf("%d\n", l);
  // base condition
  if (l == N - 1 && ST.find(s) == ST.end()) {
    // print_indent(indent);
    printf("%s\n", s.c_str());
    ST.insert(s);
    return;
  }
  // recursion
  for (int i = l; i < N; ++i) {
    std::swap(s[l], s[i]);
    solve(indent + 1, s, l + 1);
    std::swap(s[l], s[i]);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    char buf[1024];
    scanf("%s", buf);
    N = strlen(buf);
    std::string s = buf;
    solve(0, buf, 0);
  }
  
  return 0;
}

