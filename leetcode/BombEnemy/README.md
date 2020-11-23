# Problem

[Bomb Enemy](https://leetcode.com/problems/bomb-enemy/)

2차원 배열 `G[][]` 가 주어진다. `G[][]` 는 `W, E, 0` 으로만 구성되어
있다. 사방으로 길게 뻗는 폭탄을 놓을 수 있다. 최대로 해치울 수 있는
적의 개수를 구하라.

# Idea

`G` 를 Exhaustive Search 한다. `ans` 를 선언하여 답을
저장한다. `killrow, killcol[]` 를 선언한다.  `killrow` 는 현재 위치와
같은 행에서 현재 열까지 놓여있는 적들의 개수이다. `killcol[]` 은 현재
위치와 같은 열에서 현재 행까지 놓여있는 적들의 개수이다. `killrow,
killcol[]` 는 과거의 행적들을 기반으로 캐시되어있는 값이고
현재위치에서 아래방향과 오른쪽 방향은 `W` 가 나올때까지 매번 구한다.

인덱스 `y, x` 를 이용하여 `G[][]` 를 순회하며 다음을 반복한다.

0. `G[y][x]` 가 첫열이거나 `G[y][x-1] == 'W'` 이면
   `killrow` 를 `0` 으로 초기화한다. 오른쪽 방향으로 순회하면서
   `E` 의 개수를 `killrow` 에 더한다.
1. `G[y][x]` 가 첫행이거나 `G[y-1][x] == 'W'` 이면
   `killcol[x]` 를 `0` 으로 초기화한다. 아래쪽 방향으로 순회하면서
   `E` 의 개수를 `killcol[x]` 에 더한다.
2. `G[y][x] == 0` 이면 폭탄을 놓을 수 있다. `ans = max(r, killrow +
   killcol[x])` 를 수행한다.

# Implementation

* [c++11](a.cpp)
* [go](a.go)

# Complexity

```
O(HW) O(W)
```
