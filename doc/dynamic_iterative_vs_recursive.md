# Abstract

- recursion 을 이용하여 dynamic programming 하는 방법을 recursive
  dynamic programming 이라고 한다.  반면에 recursion 을 이용하지 않고
  loop statement 를 활용하여 dynamic programming 하는 방법을 iterative
  dynamic programming 이라고 한다.
  
# [TRIPATHCNT](https://algospot.com/judge/problem/read/TRIPATHCNT) iterative way

- iterative dynamic programming 으로 해결해보자.

```cpp
int N, trangle[100][100];
int CACHE[100][100];
int solve() {
    // calculate base condition
    // 바닥에 도달했을 경우가 기저 사례이다.
    for (int x = 0; x < N; ++x) {
        CACHE[N-1][x] = transgle[N-1][x];
    }
    // calculate recursion
    // 바닥 바로 윗줄 부터 시작행까지 올라오자.
    for (int y = N-2; y >= 0; --y) {
        for (int x = 0; x < y+1; ++x) {
            CACHE[y][x] = std::max(CACHE[y+1][x], CACHE[y+1][x+1]) + triangle[y][x];
        }
    }
    // 맨 위칸의 정보를 리턴하자.
    return CACHE[0][0];
}
```

# [TRIPATHCNT](https://algospot.com/judge/problem/read/TRIPATHCNT) iterative way with sliding window

- iterative dynamic programming 으로 하면서 space complexity 를 최적화
  해보자. CACHE 는 단 두행만 필요하다. 두행을 한행씩 슬라이딩 하면서 사용하자.
  
```cpp
int N, trangle[100][100];
int CACHE[2][10000];
int solve() {
    // caculate base condition
    for (int x = 0; x < N; ++x) {
        CACHE[(N-1)%2][x] = triangle[N-1][x];
    }
    // caculate recursion
    for (int y = N-2; y >= 0; --y) {
        for (int x = 0; x < y+1; ++x) {
            CACHE[y%2][x] = std::max(CACHE[(y+1)%2][x], CACHE[(y+1)%2][x+1]) + triangle[y][x];
        }
    }
}
```

# recursive dynamic programming

- 장점
  - 직관적이다.
  - 부분 문제 간의 의존 관계나 계산 순서에 대해 고민 할 필요가 없다.
  - 전체 부분 문제 중 일부의 답만 필요할 경우 더 빠르게 동작한다.
- 단점
  - 슬라이딩 윈도 기법을 쓸 수 없다.
  - 스택 오버플로를 조심해야 한다.

# iterative dynamic programming

- 장점
  - 구현이 더 짧다.
  - 재귀 호출에 필요한 부하가 없기 때문에 성능이 좋다.
  - 슬라이딩 윈도 기법을 쓸 수 있다.
- 단점
  - 구현이 직관적이 못해 어렵다.
  - 부분 문제 간의 의존 관계를 고려해 계산되는 순서를 고민해야 한다.