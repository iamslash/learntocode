# Problem

> [Bomb Enemy](https://leetcode.com/problems/bomb-enemy/)

2차원 배열 `G[][]` 가 주어진다. `G[][]` 는 `W, E, 0` 으로만 구성되어
있다. 사방으로 길게 뻗는 폭탄을 놓을 수 있다. 최대로 해치울 수 있는
적의 개수를 구하라.

# Idea

`G` 를 Exhaustive Search 한다. 

다음과 같은 변수들을 선언한다.

> * `glbMax` : 답
> * `killRow` : 현재 위치와 같은 행에서 처치할 수 있는 적군 수
> * `killCols` : 현재 위치와 같은 열에서 처치할 수 있는 적군 수

`G[][]` 를 순회할 때 `G[y][x] == 0` 일 때 마다 매번 `killRow,
killCols` 를 구할필요는 없다. `y == 0 || G[y-1][x] == 'W'` 일 때와 `x
== 0 || G[y][x-1] == 'W'` 일 때만 `killRow, killCols` 를 구해도
된다. `G[y][x] == '0'` 일 때는 `glbMax` 를 업데이트 한다.

인덱스 `y, x` 를 이용하여 `G[][]` 를 순회하며 다음을 반복한다.

0. `G[y][x]` 가 첫열이거나 `G[y][x-1] == 'W'` 이면
   `killrow` 를 `0` 으로 초기화한다. 오른쪽 방향으로 순회하면서
   `E` 의 개수를 `killrow` 에 더한다.
1. `G[y][x]` 가 첫행이거나 `G[y-1][x] == 'W'` 이면
   `killcol[x]` 를 `0` 으로 초기화한다. 아래쪽 방향으로 순회하면서
   `E` 의 개수를 `killcol[x]` 에 더한다.
2. `G[y][x] == 0` 이면 폭탄을 놓을 수 있다. `glbMax = max(glbMax,
   killrow + killcol[x])` 를 수행한다.
   
모든 반복을 마치면 `glbMax` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)
* [go](a.go)

# Complexity

```
O(HW) O(W)
```
