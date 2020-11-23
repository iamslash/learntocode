// Copyright (C) 2016 by iamslash

#include <cstdio>

int bit_cnt(const int& c) {
  // base condition
  if (c == 0)
    return 0;
  int r = c % 2;
  // recursion
  return r + bit_cnt(c >> 1);
}

void print_bit_mask(const int& n) {
  char c = static_cast<char>(n);
  for (int i = 7; i >= 0; --i) {
    printf("%1d", c & (1 << i) ? 1 : 0);
  }
  printf("\n");
}

// get minimum set bit index using 2's complement
// n = 00011000
// 1's = 11100111
// 2's = 11101000
int get_min_set_bit(const int& n) {
  return n & (-n);
}

int main() {
  char BM = 0x03;

  //
  print_bit_mask(BM);
  printf("%d\n", bit_cnt(BM));

  // null set, full set
  BM = 0;
  print_bit_mask(BM);
  BM = static_cast<char>((1 << 20) - 1);
  print_bit_mask(BM);

  // add a element
  BM = 0;
  BM |= (1 << 3);
  print_bit_mask(BM);

  // check a element included
  BM = 0;
  BM |= (1 << 3);
  printf("%s\n", (BM & (1 << 3)) ? "true" : "false");
  printf("%s\n", (BM & (1 << 4)) ? "true" : "false");
  
  // dell a element
  BM |= (1 << 3);
  BM |= (1 << 4);
  BM ^= (1 << 3);
  print_bit_mask(BM);
  
  // toggle a element
  BM = 0x08;
  for (int i = 0; i < 3; ++i) {
    BM ^= (1 << 3);
    print_bit_mask(BM);
  }

  // set operation (added, intersection, removed, toggled)
  print_bit_mask(0x01 | 0x02);
  print_bit_mask(0x03 & 0x01);
  print_bit_mask(0x03 & (~0x01));
  print_bit_mask(0x03 ^ 0x01);

  // size of set (__builtin_popcount())
  printf("%d\n", bit_cnt(0x03));
  printf("%d\n", __builtin_popcount(0x03));

  // find a min element (__builtin_ctz())
  BM = 0x08;
  printf("%d\n", get_min_set_bit(BM));
  printf("%d\n", __builtin_ctz(BM));
  
  // del a min element
  BM = 0x06;
  print_bit_mask(BM & (BM - 1));
  
  // traversal of set
  BM = 0x07;
  for (int subset = BM; subset; subset = BM & (subset - 1)) {
    print_bit_mask(subset);
  }
  
  return 0;
}
