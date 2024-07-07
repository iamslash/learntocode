# Problem

[Frog Jump](https://leetcode.com/problems/frog-jump/)

# Idea

돌이 놓여있는 좌표의 모임 `stones[]` 가 주어진다. 개구리가 `stones[0]` 부터 점프를 한다. `stones[i]` 에 도착하는데 `k` 만큼 점프했다면 `stones[i]` 에서 `k-1, k, k+1` 만큼 점프할 수 있다. 마지막 좌표까지 이동할 수 있는지 검증하는 문제이다.

예를 들어 `S = [0, 1, 3, 5, 6, 8, 12, 17]` 의 경우를 살펴보자.

```
S: 0 1 3 5 6 8 12 17
   . 1
     . 2
       . 2
         . 3
             .  4
                .  5
                   .
ans: true
```

`Map<Integer, Set<Integer>> stoneLastJumpsMap` 를 선언하여 `{position of stone, last jumps}` 를 저장한다. 즉, `stoneLastJumpsMap[0]` 은 `0` 위치 까지 도착하기 위해 사용한 jump 값 들이 저장된다. 그래서 `stoneLastJumpsMap[stones[n - 1]]` 은 `stones[n - 1]` 위치 까지 도착하기 위해 사용한 jump 값들이 저장된다. 문제의 조건에 의해 `stoneLastJumpsMap[0]` 에 `1` 을 추가한다.

인덱스 `i` 를 `[0, n-1]` 동안 순회하면서 다음을 반복한다.

- 값 `jump` 를 `stoneLastJumpsMap.get(stones[i])` 동안 순회하면서 다음을 반복한다.
  - `reachPos` 에 `stones[i] + jump` 를 저장한다. `reachPos` 는 다음 stone 위치를 말한다. 
  - `reachPos == stones[n - 1]` 이면 `true` 를 리턴한다.
  - `stoneLastJumpsMap.get(reachPos)` 가 있다면 `jump - 1, jump, jump + 1` 를 저장한다.

모든 loop 을 마치면 마지막 위치까지 도착할 방법이 없다는 것을 의미한다. `false` 를 리턴한다.

# Implementation

* [java17](MainApp.java)

# Complexity

```
O(N^2) O(N)
```
