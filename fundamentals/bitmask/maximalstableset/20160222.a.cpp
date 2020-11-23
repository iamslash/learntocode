// Copyright (C) 2016 by iamslash

// 문제의 정의가 명확하지 않다. 한개만 더 넣으면 폭발하는 집합을
// 구하라는 건가?  explodes[i]는 i번째 원소와 함께 존재하면 터지는
// 모든 원소일까 아니면 일부 원소일까
//
// 한개만 더 넣으면 폭발하는 극대 안정 집합의 수를 구한다고 가정했다.
// explodes[i]는 i번째 원소와 함께 존재하면 터지는 원소들의 목록이라고 가정했다.

#include <cstdio>
#include <cstdint>

#define MAX_N 65535

int N;
int explodes[MAX_N] = {0,};

void PrintBitmask(int set) {
  printf("  ");
  for (int i = 7; i >= 0; --i) {
    printf("%d", (set & (1 << i)) ? 1 : 0);
  }
  printf("\n");
}

bool IsStable(int set) {
  for (int i = 0; i < N; ++i) {
    if (explodes[i] == 0)
      continue;
    // ith 원소가 set에 있고 explodes[i]가 set에 존재하는가?
    if ((set & (1 << i)) && (set & explodes[i]))
      return false;
  }
  return true;
}

int CountStableSet() {
  int r = 0;

  // 0x01, 0x02, 0x03
  for (int set = 1; set < (1 << N); ++set) {
    // 안정적이지 않다면 더이상 생각해 볼 필요가 없다.
    if (!IsStable(set))
      continue;
    PrintBitmask(set);
    // 극대 안정 집합인지 확인하기 위해, 넣을 수 있는 다른 물질이 있나
    // 확인한다.
    bool can_extend = false;
    for (int add = 0; add < N; ++add) {
      // add가 set에 존재하지 않고 
      if ((set & (1 << add)) == 0 && (explodes[add] & set) == 1) {
        can_extend = true;
        break;
      }
    }
    if (!can_extend) {
      ++r;
    }
  }

  return r;
}

int main()
{
  // total 5 elements
  N = 3;
  // 0th element will explode with 3th element
  explodes[0] = 0x02;
  int element = 0x00;
  
  // element = 0x02;
  // printf("%x is %d\n", element, IsStable(element));
  // element = 0x09;
  // printf("%x is %d\n", element, IsStable(element));
  printf("%d\n", CountStableSet());

  return 0;
}
