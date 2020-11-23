// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <vector>

int N, K;

void PrintVInt(const std::vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
      printf("%d ", v[i]);
    }
    printf("\n");
}

void PickNumbers(int n, int topick, std::vector<int>& picked) {
  // base condition : already picked
  if (topick == 0) {
    PrintVInt(picked);
    return;
  }
  
  // recursion
  int j = picked.size() == 0 ? 0 : picked.back() + 1;
  for (int i = j; i < N; ++i) {
    picked.push_back(i);
    PickNumbers(N, topick - 1, picked);
    picked.pop_back();
  }
}

int main() {
  N = 3;
  K = 2;

  std::vector<int> picked;

  PickNumbers(N, K, picked);
  
  return 0;
}
