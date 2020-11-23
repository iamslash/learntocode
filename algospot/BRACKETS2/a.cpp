// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/BRACKETS2

#include <cstdio>
#include <string>
#include <stack>

bool Solve(const std::string& s) {

  std::stack<char> bs;

  for (const char& c : s) {
    if (c == '(' || c == '{' || c == '[') {
      bs.push(c);
    } else if (c == ')') {
      if (bs.top() == '(') {
        bs.pop();
      } else { return false; }      
    } else if (c == '}') {
      if (bs.top() == '{') {
        bs.pop();
      } else { return false; }      
    } else if (c == ']') {
      if (bs.top() == '[') {
        bs.pop();
      } else { return false; }      
    }
  }

  if (bs.size() > 0)
    return false;

  return true;
}

int main() {

  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    char buf[10001] = {0,};
    scanf("%s", buf);
    printf("%s\n", Solve(std::string(buf)) ? "YES" : "NO");
  }

  return 0;
}
