# Abstract

- 같이 두었을 때 서로 반응해 폭발하는 물질들이 있다고 해보자. 물질이
  하나만 있는 집합은 항상 안정적이다. 물질을 하나라도 추가하면 폭발이
  일어나는 집합들을 maximal stable set(극대 안정 집합)이라고 한다.
- 예를 들어서 4개의 화학 물질 A, B, C, D가 있는데 A와 B를 같은 상자에
  넣거나, C와 D를 같은 상자에 넣으면 폭발한다고 하자. 그러면 다음과
  같은 네개의 극대 안정 집합이 존재한다. {A, C}, {A, D}, {B, C}, {B,
  D}

# Implementation

- {A}는 답이 아니다. 아직 C를 투입할 수 있기 때문에 극대가 아니다.
- 부분집합을 순회하면서 안정적인 부분집합만 고려하자. 그 부분집합들
  중에 아직 투입되지 않은 녀석을 투입하여 폭발하지 않는 녀석은 극대가
  아니다. 그런 녀석이 하나도 존재하지 않는다면 maximal stable set이
  맞다.  카운트를 하나 올리자.

```cpp
#define MAX_N 65535

int N;
// explodes[i] = bitmask set which is i-th element will be exploded with
int explodes[MAX_N] = {0, };

// set is stable ???
bool is_stable(int set) {
  for (int i = 0; i < N; ++i) {
    if ((set & (1 << i)) && (set & explodes[i]))
      return false;
  }
  return true;
}

// get count of maximal stable set
int solve() {
  int r = 0;

  for (int set = 1; set < (1 << N); ++set) {
    if (!is_stable(set))
      continue;

    bool can_extend = false;
    for (int i = 0; i < N; ++i) {
      if (((set & (1 << i)) == 0) && ((set & explodes[i]) == 0)) {
        // printf("%x %d\n", set, i);
        can_extend = true;
        break;
      }
    }
    if (!can_extend)
      ++r;
  }

  return r;
}

int main() {
  N = 4;
  explodes[0] = 0x02;  // 00000010
  explodes[1] = 0x01;  // 00000001
  explodes[2] = 0x08;  // 00001000
  explodes[3] = 0x04;  // 00000100
  printf("%d\n", solve());
  return 0;
}
```
