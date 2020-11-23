// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdint>

// get the value which is wrote on mask at index
// index is 15 puzzle's index
int get_15(uint64_t mask, int index) {
  return (mask >> (index << 2)) & 0x0f;
}

// set the value which is on mask at index
uint64_t set_15(uint64_t mask, int index, uint64_t value) {
  return mask | ((value & 0x0F) << (index << 2));
}

int main()
{
  // uint64_t BM = 0x00;
  // BM = set_15(BM, 1, 3);
  // printf("%d\n", get_15(BM, 1));
  uint64_t puzzle = 0x00;
  for (int i = 0; i < 16; ++i) {
    puzzle = set_15(puzzle, i, i);
  }
  for (int i = 0; i < 16; ++i) {
    printf("[%2d] %2d\n", i, get_15(puzzle, i));
  }
}
