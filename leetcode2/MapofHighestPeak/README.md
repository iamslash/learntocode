# Problem

[Map of Highest Peak](https://leetcode.com/problems/map-of-highest-peak/)

2d array `isWater` 가 주어진다. `isWater[y][x] == 1` 이면
물이다. `isWater[y][x] == 0` 이면 땅이다. 다음과 같은 조건을 만족하는
`height[][]` 를 구하라.

* `height[][]` 의 행과 열의 크기는 `isWater[][]` 와 같다.
* 물은 `height[][] = 0` 이다.
* 땅은 `height[][] > 0` 이다. 
* 인접한 땅의 높이 차이는 최대 1 이다.

`height[][]` 의 합이 최대가 되도록 하라.

# Idea

[bfs](/fundamentals/graph/bfs/README.md) 를 이용하여 해결할 만 하다.

예를 들어 다음과 같은 경우를 살펴보자.

```
isWater:
0 1
0 0

height:
- 0    1 0    1 0    1 0
- -    - 1    2 1    2 1 

bfsq:
0,1    0,0    1,0
```

# Implementation

* [python3](a.py)

# Complexity

```
O(HW) O(HW)
```
