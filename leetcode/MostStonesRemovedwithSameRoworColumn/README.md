# Problem

[Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)

# Idea

2D 평면에 돌이 놓여진 좌표들의 모임 `S[][]` 가 주어진다. `x` 혹은 `y`
가 같은 돌을 제거할 수 있다. 최대로 제거할 수 있는 돌의 개수를 구하는
문제이다.

예를 들어 `S = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}}` 를
살펴보자. 다음과 같이 `x` 혹은 `y` 를 공유하는 덩어리는 하나 존재하고
하나씩 제거해 나가면 마지막 하나가 남는다.

```
   x x
 x . x
 x x
```

잘 생각해 보면 덩어리마다 하나의 돌을 제외하고는 모두 제거할 수 있다.
따라서 전체 돌의 개수에서 `x` 혹은 `y` 를 공유하는 덩어리의 개수를
빼면 최대 제거할 수 있는 돌의 개수와 같다.

덩어리의 개수는 어떻게 구할 것인가? 이것은
[union-find](/fundamentals/disjointset/unionfind/README.md) 를
이용하여 덩어리별 집합을 만들고 그것의 개수를 구하면 된다.

돌의 좌표 `x, y` 가 주어지면 둘은 한덩어리 이므로 `union(x, y +
10000)` 한다. 문제의 조건에 의해 `0 <= S[i][j] < 10000` 이다. `x, y`
둘다 하나의 벡터에 저장되어야 하므로 둘을 구분짓기 위해 `y + 10000`
한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
