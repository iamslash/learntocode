# Problem

> [Shortest Path in a Hidden Grid](https://leetcode.com/problems/shortest-path-in-a-hidden-grid/)

`GridMaster master` 가 주어진다. `master` 는 다음과 같은 method 를
가지고 있다.

* `boolean GridMaster.canMove(char direction)`
* `void GridMaster.move(char direction)`
* `boolean GridMaster.isTarget()`

`master` 가 놓여진 곳부터 `master.isTarget == True` 인 곳까지 최단
거리를 구하라.

# Idea

DFS 를 수행하고 `graph = dict()` 에 `{(dy, dx), master.isTarget()}` 를 저장한다.

BFS 를 수행하고 `(0,0)` 부터 `graph[?,?] == True` 까지의 거리를 구한다.

# Implementation

* [python3](a.py)

# Complexity

```
O(HW) O(HW)
```
