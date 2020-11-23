# Problem

[Cat and Mouse](https://leetcode.com/problems/cat-and-mouse/)

이차원 배열 `G[][]` 가 주어진다. Mouse 는 node `1` 에서 출발하고 Cat
는 node `2` 에서 출발한다. Mouse 가 먼저 시작하여 서로 한번씩
전진한다. Mouse 가 `0` 에 도착하면 Mouse 가 이기는 것이고 답은 `1`
이다. Cat 이 Mouse 를 잡으면 Cat 이 이기는 것이고 답은 `2` 이다.
그렇지 않은 경우는 서로 비기는 경우이고 답은 `0` 이다. Mouse, Cat 이
서로 optimal 하게 전진할 때 승부의 결과를 구하라.

# Idea

`int[n+n][n][n] C` 를 선언하여 `-1` 로 초기화 한다. `C[turn][mouse
turn][cat turn]` 에 승부의 결과를 저장한다.

다음과 같은 부분 문제 `dfs` 를 선언하여 dynamic programming 으로
해결한다.

```
int dfs(int[][] G, int[][][] C, int totTurn, int mouseTurn, int catTurn)

   return: result of game. 0 or 1 or 2
        G: graph
        C: cache
  totTurn: total game turn     
mouseTurn: turn of mouse
  catTurn: turn of cat
```

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N^3) O(N^3)
```
