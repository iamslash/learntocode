// Copyright (C) 2017 by iamslash

// Stack of Boxes: You have a stack of n boxes, with widths W i'
// heights hi' and depths d 1? The boxes cannot be rotated and can
// only be stacked on top of one another if each box in the stack is
// strictly larger than the box above it in width, height. and
// depth. Implement a method to compute the height of the tallest
// possible stack.The height of a stack is the sum of the heights of
// each box.

#include <cstdio>
#include <vector>
#include <algorithm>

int N;
std::vector<std::vector<int>> BOXES;
int CACHE[100];

void print_boxes() {
  for (int i = 0; i < BOXES.size(); ++i)
    printf("%d %d %d\n", BOXES[i][0], BOXES[i][1], BOXES[i][2]);
}

int solve(int from) {
  // printf("  %d\n", from);
  // base condition
  if (from >= N)
    return 0;
  // memoization
  int& r = CACHE[from];
  if (r != -1)
    return r;
  // recursion
  r = solve(from + 1);
  r = std::max(BOXES[from][1] + r, r);
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < 100; ++i)
      CACHE[i] = -1;
    scanf("%d", &N);
    BOXES.clear();
    for (int i = 0; i < N; ++i) {
      std::vector<int> b(3, 0);
      scanf("%d %d %d", &b[0], &b[1], &b[2]);
      BOXES.push_back(b);
    }
    // print_boxes();
    printf("%d\n", solve(0));
  }
  return 0;
}
