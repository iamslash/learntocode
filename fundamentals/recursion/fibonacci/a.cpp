// Copyright (C) 2016 by iamslash

// https://www.tutorialspoint.com/data_structures_algorithms/fibonacci_recursive_program_in_c.htm
//
// Fibonacci series satisfies the following conditions
// Fn = Fn-1 + Fn-2

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cstring>
#include <queue>

int fibonacci_r(int n) {
  // base condition
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  // recursion
  } else {
    return fibonacci_r(n - 1) + fibonacci_r(n - 2);
  }
}

// n: 3 2 1 0
// a: 0 1 1 2 
// b: 1 1 2 3
int fibonacci_i(int n) {
  int a = 0, b = 1;
  while (n-- > 0) {
    std::swap(a, b);
    b += a;
  }
  return a;
}

int main() {
  printf("%d th fibonacci is %d\n", 10, fibonacci_r(10));
  printf("%d th fibonacci is %d\n", 10, fibonacci_i(10));
  return 0;
}
