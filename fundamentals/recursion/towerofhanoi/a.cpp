// Copyright (C) 2016 by iamslash
//
// https://www.tutorialspoint.com/data_structures_algorithms/tower_of_hanoi.htm
//
// Tower of Hanoi, is a mathematical puzzle which consists of three
// towers (pegs) and more than one rings is as depicted
//
// These rings are of different sizes and stacked upon in an ascending
// order, i.e. the smaller one sits over the larger one. There are
// other variations of the puzzle where the number of disks increase,
// but the tower count remains the same.

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cstring>
#include <queue>

void hanoi(int n, char from, char to, char by) {
  // base condition
  if (n == 1) {
    printf("%2d, %c => %c\n", n, from, to);
    return;
  }

  // recursion
  hanoi(n - 1, from, by, to);
  printf("%2d, %c => %c\n", n, from, to);
  hanoi(n - 1, by, to, from);
}


int main() {
  hanoi(3, 'A', 'C', 'B');

  return 0;
}
