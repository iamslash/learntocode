// Copyright (C) 2016 by iamslash
// http://www.practice.geeksforgeeks.org/problem-page.php?pid=246

#include <iostream>
#include <cstdint>
using namespace std;

// count number of 1 should be just one.
bool IsPowerOf2(long long int n) {

  int r = 0;
  for (int i = 0; i < 64; ++i) {
    long long int t = (n >> i) & 0x01;
    if (t > 0)
      ++r;
    if (r > 1)
      break;
  }

  // printf("%d %d\n", n, r);
  
  return r == 1;
}

int main() {
  //code
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    long long int N;
    scanf("%lld", &N);

    printf("%s\n", IsPowerOf2(N) ? "YES" : "NO");
  }
	
  return 0;
}
