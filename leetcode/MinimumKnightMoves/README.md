# Problem

[Minimum Knight Moves](https://leetcode.com/problems/minimum-knight-moves/)

좌표 `ex, ey` 가 주어진다. 체스의 기사를 `0, 0` 에서 시작하여 `ex, ey`
까지 움직였을 때 최소의 회수를 구하는 문제이다.

# Idea

한 점에서 다른 점으로 최단 경로를 구하는
문제이다. [BFS](/fundamentals/graph/bfs/README.md) 를 이용하여 해결할
수 있다.

단, 주의할 점이 있다. 다음과 같이 steps 의 개수가 3 미만일 때를
제외하고는 `ex, ey` 방향으로 움직이도록 하여 pruning 할 수 있다.

```go
        if _, exists := seen[nx][ny]; !exists &&
          (nx * ex >= 0 && ny * ey >= 0 || steps < 3) {
          seen[nx][ny] = true
          q = append(q, []int{nx, ny})
        }
```

# Implementation

* [go](a.go)
* [java11](MainApp.java)

# Complexity

```
// O(8^N) O(8^N)
// N is a distance
```
