# Problem

[Minimum Moves to Move a Box to Their Target Location](https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/)

2D Matrix `G[][]` 가 주어진다. 각 cell 은 `., #, B, S, T` 로만 구성되어 있다.

* `.` 는 길이다. 도착할 수 있다.
* `#` 는 벽이다. 도착할 수 없다.
* `B` 는 박스이다.
* `S` 는 일꾼이다.
* `T` 는 목표지점이다. 

일꾼이 `B` 를 밀어서 `T` 에 도착하기 위한 `B` 의 최소 이동 거리를
구하라

# Idea

cost 가 1 이고 최소 거리 문제이다. `BFS` 로 해결할 만 하다.

다음과 같이 두가지의 BFS 를 생각해 볼 수 있다.

* `B` 에서 `T` 까지 가는 최소 거리를 위한 BFS
* `S` 에서 `B` 까지 가는 최소 거리를 위한 BFS
  * `S` 에서 `B` 까지 이동하면 `B` 를 움직인다.

`queue<int> q` 를 선언하여 BFS queue 로 이용한다. `[ y of box, x of
box, y of worker, x of worker ]` 를 encoding 하여 `q` 에
저장한다. `unordered_map<int, int>` 를 선언하여 `dist[encoded state]`
에 Box 가 `G[y][x]` 에 있을 때 이동한 최소거리를 저장한다.

# Implementation

* [java8](solution.java)

# Complexity

```
O(HW) O(HW)
```
