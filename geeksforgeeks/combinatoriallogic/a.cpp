// Copyright (C) 2016 by iamslash
// http://www.practice.geeksforgeeks.org/problem-page.php?pid=1365

#include <iostream>
#include <cstdint>

int N[6];

bool Solve(int * n) { 
  return (!n[0] & n[1]) + (n[2] & n[3]) + (n[4] & !n[5]);
}

int main() {
  //code
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {

    for (int i = 0; i < 6; ++i) {
      scanf("%d", &N[i]);
    }

    printf("%d\n", Solve(N));
  }
	
  return 0;
}
