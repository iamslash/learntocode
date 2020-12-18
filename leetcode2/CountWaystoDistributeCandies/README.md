# Problem

[Ways to Distribute Candies](https://leetcode.com/problems/count-ways-to-distribute-candies/)

숫자 `n, k` 가 주어진다. `n` 개의 캔디를 `k` 개의 가방에 나누어 담는
경우의 수를 구하라. 단, 한개의 가방에는 최소한 한개의 캔디가 있어야
한다.

# Idea

예를 들어 `n = 3, k = 2` 인 경우를 살펴보자.

```
[1],[2,3]
[2],[1,3]
[3],[1,2]
```

따라서 답은 `3` 이다.

캐시 `vector<vector<int>> C(n, vector<int>(k))` 를 선언한다.
`C[n][k]` 에 `n` 개의 캔디를 `k` 개의 가방에 나누어
담는 경우의 수를 저장하자. 다음과 같은 규칙을 발견할 수 있다.

```
C[n][k] = k * C[n-1][k] + C[n-1][k-1]
```

* `k * C[n-1][k]`
  * 1 개의 가방안에 최소한 1 개의 캔디는 있어야 한다. 1 개의 캔디가
    임의의 가방에 있을 때 마다 나머지 캔디 (n-1) 가 k 개의 가방에
    배포되는 경우
* `C[n-1][k-1]`
  * 1 개의 가방안에 최소한 1 개의 캔디는 있어야 한다. 1 개의 캔디가
    임의의 가방에 있고 나머지 캔디 (n-1) 가 `k-1` 개의 가방에 배포되는
    경우

이때 `C[i][i] == 1` 이고 `C[i][1] == 1` 임은 자명하다.

`vector<int> C(k+1, 1)` 를 선언하여 space complexity 를
개선할 수 있다.

```
C[k] = k * C[k] + C[k-1]
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(K) O(K)
```
