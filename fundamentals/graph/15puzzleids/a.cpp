// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>

int best;

class State {
 public:
  // 0이 상하좌우로 이동했을때 각 State을 계산해서 리턴한다.
  std::vector<State> get_adj() const {
    std::vector<State> r;
    for (int i = 0; i < 4; ++i) {
      State s = *this;
      s.move(i);
      if (bitmask != s.bitmask)
        r.push_back(s);
    }
    return r;
  }
  // map은 ordered map이기 때문에 비교 연산자가 필요하다.
  bool operator < (const State& rhs) const {
    return bitmask < rhs.bitmask;
  }
  // 종료상태와 비교하기 위한 연산자가 필요하다.
  bool operator == (const State& rhs) const {
    return bitmask == rhs.bitmask;
  }
  // 상태를 64bit intager로 표현한다.
  uint64_t bitmask;
  explicit State(uint64_t a[16]) {
    bitmask = 0;
    for (int i = 0; i < 16; ++i) {
      bitmask = bitmask | ((a[i] & 0x0f) << (i << 2));
    }
  }
  State(const State& rhs) : bitmask(rhs.bitmask) {
  }
  // 0을 dir로 움직여라 움직이지 못하는 경우는 그대로
  // 0(상), 1(우), 2(하), 3(좌)
  void move(int dir) {
    int zidx = get_zero_idx();
    int didx = 0;
    switch (dir) {
      case 0:  // up
        if (zidx < 4)
          return;
        // swap
        didx = zidx - 4;
        break;
      case 1:  // right
        if ((zidx % 4) == 3)
          return;
        didx = zidx + 1;
        break;
      case 2:  // down
        if (zidx > 11)
          return;
        didx = zidx + 4;
        break;
      case 3:  // left
        if ((zidx % 4) == 0)
          return;
        didx = zidx - 1;
        break;
    }
    swap(zidx, didx);
  }
  // idx에 해당하는 값
  uint64_t get(int idx) const {
    return (bitmask >> (idx << 2)) & 0x0f;
  }
  int set(int idx, uint64_t val) {
    bitmask = bitmask & ~((uint64_t)0x0f << (idx << 2));
    bitmask = bitmask | ((val & 0x0f) << (idx << 2));
    return val;
  }
  void swap(int src, int dst) {
    uint64_t dval = get(dst);
    uint64_t sval = get(src);
    set(src, dval);
    set(dst, sval);
  }
  // 0에 해당하는 idx
  int get_zero_idx() const {
    for (int idx = 0; idx < 16; ++idx) {
      if (get(idx) == 0)
        return idx;
    }
    return -1;
  }
  void print() {
    for (int i = 0; i < 16; ++i) {
      if ((i > 0) && (i % 4) == 0)
        printf("\n");

      int a = (bitmask >> (i << 2)) & 0x0f;
      printf("%2d ", a);

      // int a = (bitmask >> (i << 2)) & 0x0f;
      // printf("%2d ", a);
    }
    printf("\n\n");
  }
};

void dfs(State here, const State& end, int steps) {
  if (steps >= best)
    return;
  if (here == end) {
    best = steps;
    return;
  }
  std::vector<State> adj = here.get_adj();
  for (int i = 0; i < adj.size(); ++i)
    dfs(adj[i], end, steps + 1);
}

int ids(State start, State end, int growthstep) {
  for (int limit = 4; ; limit += growthstep) {
    best = limit + 1;
    dfs(start, end, 0);
    if (best <= limit)
      return best;
  }
  return -1;
}


int main() {
  uint64_t a[16] = { 7,  8,  4,  1,
                     2,  3,  0,  5,
                     6,  9, 10, 11,
                    12, 13, 14, 15};
  // uint64_t a[16] = { 1,  2,  3,  4,
  //                    5,  6,  7,  8,
  //                    9, 10, 11, 12,
  //                   0, 13, 14,  15};
  uint64_t b[16] = { 1,  2,  3,  4,
                     5,  6,  7,  8,
                     9, 10, 11, 12,
                    13, 14, 15,  0};
  State start = State(a);
  State end = State(b);
  printf("%d\n", ids(start, end, 1));

  // // test get, set
  // for (int i = 0; i < 16; ++i) {
  //   start.set(i, i);
  // }
  // // printf("%llu\n", ((uint64_t)0x0f << (15 << 2)));
  // // start.set(15, 15);
  // for (int i = 0; i < 16; ++i) {
  //   printf("%2llu ", start.get(i));
  // }
  // // printf("\n");

  // // test move
  // start.print();
  // for (int i = 0; i < 4; ++i) {
  //   start.move(0);
  //   start.print();
  // }

  // test print
  // start.print();
  // end.print();

  return 0;
}
