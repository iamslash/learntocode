# Problem

[Stone Game II](https://leetcode.com/problems/stone-game-ii/)

쌓인 돌의 모임 `P[]` 가 주어진다. Alex 와 Lee 는 쌓인 돌의 그룹들을 `1
<= X <= 2 * M` 개 만큼 교대로 가져갈 수 있다. 누군가 한번 가져갈 때
마다 `M` 은 `M = max(M, X)` 으로 업데이트된다. Alex 가 최대로 가져갈
때 그 돌의 개수를 구하는 문제이다. `X` 는 돌의 개수가 아니고 돌 그룹의
개수임을 유의하자.

# Idea

Alex 가 먼저 게임을 시작한다. Alex 차례에 가져갈 수 있는 돌의 수에서
Lee 가 가져간 돌의 수를 제거한 것이 최대가 최도록 구현한다.

먼저 캐시 `C[i][M]` 를 선언하여 `P[i]` 부터 `X` 만큼 가져갔을 때
최대로 가져갈 수 있는 돌의 개수를 저장하자.  이때 `1 <= X <= 2 * M`
이다.

다음과 같은 부분문제를 정의하고 재귀적으로 구현한다.

```
int dfs(P, C, int i, int M, int left)

     P: piles of stone
     C: cache for i, M
     i: start index of picking
     M: max(1, X)
  left: count of left stones
return: max count when i, M, left
```

* `int taken = 0` 을 선언하여 이번 차례의 사람이 가져간 돌의 수를
  저장한다.
* `int bound = min(n, i + 2 * M)` 를 선언하여 반복의 경계를 저장한다.
* 인덱스 `j` 를 이용하여 `[i..bound)` 를 순회하며 다음을 반복한다.
  * `taken += P[j]` 를 수행한다.
  * `int nM = max(M, j - i + 1)` 를 선언하여 새로운 `M` 을 저장한다.
  * `r = max(r, left - dfs(P, C, j + 1, nM, left - taken))` 를
    수행한다.
* `r` 을 리턴한다.

부분문제 `dfs` 를 구현하면 `int sum` 을 선언하여 `P[]` 를
모두 더한 것을 저장한다. `dfs(P, C, 0, 1, sum)` 가 곧 
답이다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)

# Complexity

```
O(N^3) O(N^2)
```
