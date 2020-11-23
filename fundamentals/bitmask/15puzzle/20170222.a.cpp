// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdint>

// get the value which is wrote on mask at index
// index is 15 puzzle's index
int get(uint64_t mask, int index) {
  return (mask >> (index << 2)) & 15;
}

// set the value which is on mask at index
uint64_t set(uint64_t mask, int index, uint64_t value) {
  return mask & ~(15LL << (index << 2)) | (value << (index << 2));
}

int main()
{
  uint64_t puzzle = 0x00;
  for (int i = 0; i < 16; ++i) {
    puzzle = set(puzzle, i, i);
  }
  for (int i = 0; i < 16; ++i) {
    printf("[%2d] %2d\n", i, get(puzzle, i));
  }
}
