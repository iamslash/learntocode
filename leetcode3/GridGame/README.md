# Problem

[Grid Game](https://leetcode.com/problems/grid-game/)

2차원 배열 `grid[][]` 가 주어진다. `grid.length == 2` 이다.  2 개의
로봇이 탐색을 한다. `0,0` 에서 출발하여 `1,n-1` 으로 아래 혹은
오른쪽으로만 이동할 수 있다. 첫 번쩨 로봇은 두 번째 로봇이 획득하는
포인트가 최소가 되도록 탐색한다. 두 번째 로봇은 획득하는 포인트가
최대이어야 한다. 두 번째 로봇이 획득하는 점수를 구하라.

# Idea

예를 들어 `grid = [[2,5,4],[1,5,1]]` 의 경우를 살펴보자.

```
* 5 4
* * *

* * 4
1 * *

* * *
1 5 *
```

따라서 답은 `4` 이다.

robot-1 이 지나간 곳은 점수가 `0` 이다. `*` 으로 표시하자.  robot-2 가
점수가 최대가 되도록 하려면 윗줄 혹은 아랫줄로 탐색할 수 밖에 없다. 윗 줄 점수의
합을 `topSum`, 아랫줄 점수의 합을 `botSum` 이라고 하자. 

robot-1 이 먼저 지나간다. 따라서 robot-1 은 모든 경우의 수에 대해
`max(topSum, botSum)` 이 최소가 되도록 탐색해야 한다. 그 때
`max(topSum, botSum)` 이 robot-2 가 최대로 획득하는 점수이다.

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(1)
```
