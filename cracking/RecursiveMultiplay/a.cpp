// Copyright (C) 2017 by iamslash

// Recursive Multiply: Write a recursive function to multiply two
// positive integers without using the * operator (or / operator). You
// can use addition, subtraction, and bit shifting, but you should
// minimize the number of those operations.

#include <cstdio>

int N, M;

// if smaller is even smaller is double of half smaller
// if smaller is odd smaller is double of half smaller with one bigger
int _solve(int smaller, int bigger) {
  // base condition
  if (smaller == 0)
    return 0;
  else if (smaller == 1)
    return bigger;
  // recursion
  int r = 0;
  int half_of_smaller = smaller >> 1;
  int half_of_result = _solve(half_of_smaller, bigger);
  if (smaller % 2 == 0) {
    r = half_of_result + half_of_result;
  } else {
    r = half_of_result + half_of_result + bigger;
  }
  return r;
}

int solve(int a, int b) {
  int r = 0;

  int bigger = a > b ? a : b;
  int smaller = a > b ? b : a;

  return _solve(smaller, bigger);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &N, &M);
    printf("%d\n", solve(N, M));
  }
  return 0;
}
