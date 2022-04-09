# Problem

[Minimum Knight Moves](https://leetcode.com/problems/minimum-knight-moves/)

좌표 `ex, ey` 가 주어진다. 체스의 기사를 `0, 0` 에서 시작하여 `ex, ey`
까지 움직였을 때 최소의 회수를 구하는 문제이다.

# Idea

한 점에서 다른 점으로 최단 경로를 구하는
문제이다. [BFS](/fundamentals/graph/bfs/README.md) 를 이용하여 해결할
수 있다.

`ex, ey` 가 어떤 사분면에 있더라도 1 사분면에 가져다 놓고 한 결과와 같다. 즉,
`ex = abs(ex), ey = abs(ey)` 를 한 것과 같다.

`nx, ny` 를 새로 이동할 좌표라고 해보자. `nx >= -1 && ny >= -1` 인
경우만 계속 탐색한다. 그렇지 않은 경우는 가지치기 한다.

# Implementation

* [go](a.go)
* [java11](MainApp.java)

# Complexity

```
N is a distance
```
