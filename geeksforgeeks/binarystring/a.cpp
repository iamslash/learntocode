// Copyright (C) 2016 by iamslash
// http://www.practice.geeksforgeeks.org/problem-page.php?pid=132

#include <iostream>
using namespace std;

int N;
int combination(int n) {
  if (n < 2)
    return 0;
  //printf(" %d\n", n)
  return n * (n - 1) / 2;
}

int main() {
  //code
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    int n = 0;
    char buf[1000];
    scanf("%d", &N);
    scanf("%s", buf);

    for (int i = 0; i < N; ++i) {
      if (buf[i] == '1')
        ++n;
    }
    printf("%d\n", combination(n));
  }
	
  return 0;
}
