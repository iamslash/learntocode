# Abstract

- 비트마스크를 이용한 우선순위 큐를 구현해 보자.
- 우선수위 큐는 보통 O(lgN)의 시간 복잡도를 갖는다. 비트마스크를
  이용하면 O(1)의 우선순위 큐를 제작 할 수 있다. 하지만 큐의 대상이
  비트마스크로 표현되기 위해 일정 범위 안에 있어야 한다.

# Implementation

- 0 에서 191까지 숫자를 192비트의 비트마스크를 이용하여 표현해본다.

```cpp
// priority queue by bitmask
// can represent 0 ~ 191 numbers
uint64_t pqueue[3] = {0x00,};

void pq_push(int i) {
  int div = i / 64;
  int mod = i % 64;
  pqueue[div] |= (1LL << mod);
}

// return -1 when pqueue is empty
int pq_pop() {
  int r = -1;
  for (int i = 0; i < 3; ++i) {
    // __builtin_ctz returns 0 or 64 pqueue[i] is zero
    if (pqueue[i] > 0) {
      int n = __builtin_ctz(pqueue[i]);
      // printf(" [%2d] %2d\n", i, n);
      if (n < 64) {
        r = i * 64 + n;
        pqueue[i] &= ~(1LL << n);
        break;
      }
    }
  }
  return r;
}
```
