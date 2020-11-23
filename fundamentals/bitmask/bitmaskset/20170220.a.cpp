// Copyright (C) 2016 by iamslash

#include <cstdio>

int BitCount(int x) {
  if (x == 0) return 0;
  return x % 2 + BitCount(x / 2);
}

void PrintBitmask(int bitmask) {
  for (int j = 31; j >= 0; --j) {
    printf("%1d", bitmask & (1LL << j) ? 1 : 0 );
  }
  printf("\n");
}

int main()
{
  // null set, full set
  int zero_bitmask = 0;
  int full_bitmask = (1 << 20) - 1;
  
  // add a element
  int bitmask = 0;
  int n = 2;
  bitmask |= (1 << n);
  
  // // check a element included
  // if (bitmask & (1 << n))
  //   printf("%d th element is in\n");
  
  // // del a element
  // bitmask &= ~(1 << n);
  
  // // toggle a element
  // bitmask ^= (1 << n);
  
  // // set operation (added, intersection, removed, toggled)
  // int a = 0x01;
  // int b = 0x10;
  // int added_bitmask = (a | b);
  // int inter_bitmask = (a & b);
  // int remov_bitmask = (a & ~b);
  // int toggl_bitmask = (a ^ b);
  
  // // size of set (__builtin_popcount())
  // printf("size is %d\n", __builtin_popcount(a));
  // printf("size is %d\n", BitCount(a));
  
  // // find a min element (__builtin_ctz())
  // printf("first element is at %d\n", __builtin_ctz(a));
  // printf("first element is at %d\n", (a & -a));
  
  // // del a min element
  // a &= (a - 1);

  // traversal of set
  bitmask = 0x08;
  bitmask = 0x15;
  for (int subset = bitmask; subset; subset = ((subset - 1) & bitmask)) {
    PrintBitmask(subset);
  }
}
