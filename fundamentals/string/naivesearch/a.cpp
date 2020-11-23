// Copyright (C) 2019 by iamslash

#include <cstdio>
#include <vector>
#include <string>

std::vector<int> naive_search(const std::string& h, const std::string& n) {
  std::vector<int> r;
  for (int i = 0; i + n.size() <= h.size(); ++i) {
    bool bmatched = true;
    for (int j = 0; j < n.size(); ++j) {
      if (h[i + j] != n[j]) {
        bmatched = false;
        break;
      }
    }
    if (bmatched) {
      r.push_back(i);
    }
  }
  return r;
}

int main() {

  std::string h = "foobarbaz";
  std::string n = "ba";

  auto r = naive_search(h, n);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
