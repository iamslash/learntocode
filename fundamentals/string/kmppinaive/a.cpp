// Copyright (C) 2016 by iamslash

#include <string>
#include <vector>
#include <algorithm>

void printv(const std::vector<int>& V) {
  for (int a : V)
    printf("%d ", a);
  printf("\n");
}

//     i
// N: aabaabac
//     j
// r: 00000000 
std::vector<int> makepi(const std::string& N) {
  int n = N.size();
  std::vector<int> r(n, 0);

  // i: begin
  // j: matched
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      // not matched
      if (N[j] != N[i+j])
        break;
      // matched
      r[i+j] = std::max(r[i+j], j+1);
    }
  }

  return r;
}

int main() {
  std::string N = "aabaabac";
  auto r = makepi(N);
  printv(r);
  
  return 0;
}
