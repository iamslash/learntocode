# Problem

> [Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)

2D 평면에 돌이 놓여진 좌표들의 모임 `S[][]` 가 주어진다. `(S[i][0],
S[i][1]` 는 `(x,y)` 를 의미한다. `x` 혹은 `y` 가 같은 돌들을 제거할 수
있다. 최대로 제거할 수 있는 돌의 개수를 구하는 문제이다.

# DFS Way

## Idea

`x` 혹은 `y` 를 공유하는 돌들을 하나의 섬으로 취급한다. [NumberOfIslands @ learntocode](/leetcode/NumberOfIslands/a.cpp) 와 비슷하다.

섬에 해당하는 돌들은 하나 빼고 지울 수 있다. 따라서 최대로 제거할 수 있는 돌의 개수는 `S.length - sum(numberOfIslands - 1)` 이다.

예를 들어 `[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]` 의 경우를 살펴보자.

```
  x x
x   x
x x
```

`6 - 1 = 5` 이다. 따라서 답은 5 이다.

## Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

## Complexity

```
O(NlgN) O(N)
```

# DisjointSet Way

## Idea

예를 들어 다음과 같은 경우를 살펴보자.

```
o 
  o
```

모든 점들의 개수에서 합쳐진 것의 개수를 제거한 것이 답이다. 즉, `2 - 2 = 0` 이다.

이번에는 다른 경우를 살펴보자.

```
o 
o
```

따라서 `2 - 1 = 1` 이다.

이번에는 다른 경우를 살펴보자.

```
o
o o
```

따라서 `3 - 2 = 1` 이다.

이번에는 다른 경우를 살펴보자.

```
    o
o
o o
```

따라서 `4 - 2 = 2` 이다.

[Disjoint Set @ learntocode](/fundamentals/disjointset/unionfind/README.md) 를 이용하여 해결해보자.

`int cntNotMerged` 를 선언하여 `S.length` 를 저장한다. 

한 점의 좌표 `(x, y)` 의 `x`, `y` 각각을 DisjointSet 에 삽입한다. `x` 와 `y` 를 구분하기 위해 `y = y + 10000` 을 수행한다. 

`S[][]` 를 순회하면서 `merge(S[i][0], S[i][1]+10000)` 될 때 마다 `cntNotMerged--` 를 수행한다. `cntNotMerged` 는 자연스럽게 `numOfIslands` 의 개수가 저장된다.

모든 반복을 마치면 `S.length - cntNotMerged` 가 곧 답이다.

## Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

## Complexity

```
O(NlgN) O(N)
```

