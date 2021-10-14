# Problem

[Minimum Operations to Make a Uni-Value Grid](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/submissions/)

2 차원 배열 `grid[][]`, 숫자 `x` 가 주어진다. 임의의 `grid[i][j]` 에
`x` 를 더하거나 뺄 수 있다. `grid[][]` 의 모든 숫자가 같아지도록 `x`
를 더하거나 빼보자.  모든 수가 같아졌을 때 `x` 를 연산한 최소 횟수를
구하라.

# Idea

예를 들어 `grid = [[2,4],[6,8]], x = 2` 를 살펴보자.

```
grid:

2 4 
6 8

4 4
4 4

2 + x  = 4
4 + 0  = 4
6 - x  = 4
8 - 2x = 4
```

따라서 답은 `4` 이다.

몇 가지 흥미로운 사실이 있다. `grid = [[2,4],[6,8]], x = 10` 인 경우를
살펴보자. `x` 가 `grid[][]` 모든 수보다 크다면 문제의 조건을 만족할 수
없다.  `2 + x` 혹은 `2 - x` 를 하더라도 `grid[][]` 의 어떤수와 같도록
할 수 없다.

또한 `grid = [[2,4],[6,8]], x = 4` 인 경우를 살펴보자. `4 + x, 4 - x`
를 하더라도 `grid[][]` 의 어떤 수와 같도록 할 수 없다.

즉, 임의의 `grid[i][j]` 에 대해서 `abs(grid[i][j] - x)` 가 `x` 로
나누어 떨어져야 한다. 그리고 `abs(grid[i][j] - x) / x > 0` 이어야
한다.

`grid[][]` 의 모든 수들을 `nums[]` 에 저장한다. 그리고 `nums[]` 를
오름차순으로 정렬한다. `int median = nums[(n-1)/2]` 를 선언하고
중간값을 저장한다.

이제 `grid[][]` 의 모든 수들을 순회한다. `int diff = abs(grid[y][x] -
median)` 를 선언하고 중간값과의 차이값을 저장한다. `diff % x != 0`
이면 문제의 조건을 만족할 수 없다. `-1` 를 리턴하자. `diff % x == 0`
이면 답에 필요한 연산의 횟수를 저장한다. 즉, `ans += (diff / x)` 를
수행한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
N: H * W
```
